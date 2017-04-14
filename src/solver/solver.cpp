#include "solver.h"

Solver::Solver(DataProvider _x, DataProvider _y, TrainType _train, LossType _loss, std::vector<std::vector<int>> hiddenNums, int classes, float dropOutProb, int epoc):
    x(_x), y(_y) {
    tm = TrainFactory.getTrainMethod(_train);
    lm = LossFactory.getLossMethod(_loss);
}

void Solver::train() {
    for(int i = 0; i < epoc; ++i) {
        auto x_batch = x.getBatch(batchSize);
        while(x_batch.size() > 0) {
            auto y_batch = y.getBatch(batchSize);
            bool loss_tmp;
            tm->backward(lm->getGradient(tm->forward(x, y), loss_tmp));
            loss += loss_tmp;
            auto x_batch = x.getBatch(batchSize);
        }
    }
}

