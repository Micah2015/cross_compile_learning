#include <iostream>

#include "alg.hpp"

void printFibonacci(int n) {
    std::cout << alg::fibonacci(n) << std::endl;
}

int main() {
    for (int i = 1; i < 10; ++i) {
        printFibonacci(i);
    }
}