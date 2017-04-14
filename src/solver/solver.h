#ifndef __DL_SOLVER_H__
#define __DL_SOLVER_H__

#include <string>
#include <vector>

#include "data_provider.h"
#include "train.h"
#include "loss.h"

class Solver {
    public:
        Solver(DataProvider _x, DataProvider _y, TrainType _train, LossType _loss, std::vector<std::vector<int>> hiddenNums, int classes, float dropOutProb, int epoc);
        void train();
    private:
        int batchSize;
        DataProvider &x;
        DataProvider &y;
        TrainMethod *tm;
        LossMethod *lm;
};


#ifndef
