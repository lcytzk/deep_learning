#include <cstdio>
#include "deep.h"

int main(int argc, char *argv[]) {
    Variable* v1 = new Variable(3);
    Variable* v2 = new Variable(4);
    auto res = *v1 + v2;
    printf("%d\n", res->eval());
    return 0;
}
