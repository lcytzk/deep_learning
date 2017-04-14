#ifndef __DL_DEEP_H__
#define __DL_DEEP_H__

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

typedef int (*OP)(int , int);

class Deep {
    public:
        Deep() {}
        Deep(int value):result(value) {}
        Deep(Deep &_d1, Deep &_d2, OP _op):d1(&_d1), d2(&_d2), op(_op) {}
        Deep operator +(Deep& d) {
            return Deep(*this, d, add);
        }
        Deep operator *(Deep& d) {
            return Deep(*this, d, mul);
        }
        int eval() {
            if(op != NULL) {
                result = op(d1->eval(), d2->eval());
            }
            return result;
        }
    private:
        Deep *d1, *d2;
        OP op = NULL;
        int result;
};

#endif
