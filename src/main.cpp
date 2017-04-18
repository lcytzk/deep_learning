#include <cstdio>
#include "deep.h"
#include "Eigen/Dense"

using namespace Eigen;

int main(int argc, char *argv[]) {
    Deep<float> v2(4.2);
    Deep<float> v3(5.3);
    auto res = v2 + v3;
    printf("%f\n", res.eval());
    return 0;
}
