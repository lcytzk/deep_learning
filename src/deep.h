#ifndef __DL_DEEP_H__
#define __DL_DEEP_H__

class Deep {
    public:
        virtual Deep* operator +(Deep *d) = 0;
        virtual Deep* operator *(Deep *d) = 0;
        virtual int eval() = 0;
};

class Op {
    public:
        virtual Deep* operate(Deep *d1, Deep *d2);
};

class AddOp : public Op {
    public:
        Deep* operate(Deep *d1, Deep *d2) {
            return *d1 + d2;
        }
};

class MulOp : public Op {
    public:
        Deep* operate(Deep *d1, Deep *d2) {
            return *d1 * d2;
        }
};

class DeepOpDeep : public Deep {
    public:
        DeepOpDeep() {}
        DeepOpDeep(Deep *_d1, Deep *_d2, Op *_op):d1(_d1), d2(_d2), op(_op) {}
        Deep* operator +(Deep *d) {
            return new DeepOpDeep(this, d, new AddOp());
        }
        Deep* operator *(Deep *d) {
            return new DeepOpDeep(this, d, new MulOp());
        }
        int eval() {
            return op->operate(d1, d2)->eval();
        }
    private:
        Deep *d1;
        Deep *d2;
        Op *op;
};

class Variable : public Deep {
    public:
        Variable(int k);
        Deep* operator +(Deep *d);
        Deep* operator *(Deep *d);
        int eval() { return value; }
    private:
        int value;
};

Variable::Variable(int k):value(k) {}

Deep* Variable::operator +(Deep *d) {
    return new DeepOpDeep(this, d, new AddOp());
}

Deep* Variable::operator *(Deep *d) {
    return new DeepOpDeep(this, d, new MulOp());
}



#endif
