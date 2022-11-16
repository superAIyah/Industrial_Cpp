#include <iostream>
#include <string>
#include <vector>
#include "funcs.h"

int main(int argc, char *argv[]) {
    std::vector<int> mas({1, 3, 7, 2, 1});
    int n = atoi(argv[1]);
    int val = atoi(argv[2]);
    fill_n_my(mas.begin(), n, val);
    for (auto c : mas)
        std::cout << c << " ";
}