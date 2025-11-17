#include <iostream>
#include <stdint.h>
#include <math.h>
#include <vector>

#include "Timer.h"

uint64_t problem12() {
    Timer timer;
    uint64_t triangle = 1;
    uint64_t num = 1;
    std::vector<uint64_t> divisors;

    while (true) {

        divisors.clear();
        uint64_t s_root = (uint64_t)sqrt(triangle) + 1;

        for (uint64_t i = 1; i < s_root; i++) {
            if (triangle % i == 0) {
                divisors.push_back(i);
            }
        }

        if (divisors.size() * 2 > 500) {
            break;
        }

        num += 1;
        triangle += num;
    }

    return triangle;
}

int main() {
    uint64_t result = problem12();
    std::cout << result << "\n";
}