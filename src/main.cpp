#include <cstdio>
#include "deep.h"

int main(int argc, char *argv[]) {
    Deep v1(3);
    Deep v2(4);
    Deep v3(5);
    auto res = v1 * v2 + v3;
    printf("%d\n", res.eval());
    return 0;
}
