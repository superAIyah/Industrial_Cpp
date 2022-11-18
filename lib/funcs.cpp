#include "funcs.h"

// 0
int gen() {
    static int tmp = 0;
    return tmp++;
}