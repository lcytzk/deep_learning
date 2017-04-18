#ifndef __DL_DEEP_H__
#define __DL_DEEP_H__

template<typename T>
class Operators {
    public:
        static T add(T a, T b) {
            return a + b;
        }
        
        static T minus(T a, T b) {
            return a - b;
        }
        
        static T divide(T a, T b) {
            return a * b;
        }
        
        static T mul(T a, T b) {
            return a / b;
        }
};

template<typename T>
T add(T a, T b) {
    return a + b;
}

template<typename T>
T minus(T a, T b) {
    return a - b;
}

template<typename T>
T divide(T a, T b) {
    return a / b;
}

template<typename T>
T mul(T a, T b) {
    return a * b;
}

template<typename T>
class Deep {
    public:
        Deep() {}
        Deep(int value):result(value) {}
        Deep(int value):result(value) {}
        Deep(Deep &_d1, Deep &_d2, T (*_op)(T, T)):d1(&_d1), d2(&_d2), op(_op) {}
        Deep operator +(Deep& d) {
            return Deep(*this, d, add<T>);
        }
        Deep operator *(Deep& d) {
            return Deep(*this, d, mul<T>);
        }
        T eval() {
            if(op != NULL) {
                result = op(d1->eval(), d2->eval());
            }
            return result;
        }
    private:
        Deep *d1, *d2;
        T (*op)(T, T) = NULL;
        T result;
};

#endif
