#ifndef __DL_TRAIN_H__
#define __DL_TRAIN_H__

#include <vector>

#include "example.h"

class TrainType {
    public:
        static int SGD = 1;
        static int ADAM = 2;
        static int RMSPROP = 3;
};

typedef Score vector<float>;

class TrainMethod {
    public:
        TrainMethod(vector<int> &hiddenNums);
        Score* forward(std::vector<Example*> x, int y);
        void backward(Grad gradient);
};

TrainMethod::forward {}

class TrainMethodFactory {
    public:
        static TrainMethod* getTrainMethod(TrainType type);
};



#endif
