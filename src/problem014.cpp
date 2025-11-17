// https://stackoverflow.com/questions/2229107/what-is-the-fastest-way-to-find-if-a-number-is-even-or-odd

#include <iostream>
#include <stdint.h>

#include "Timer.h"

uint64_t problem14() {
    Timer timer;
    constexpr uint32_t LIMIT = 1000000;
    static uint32_t aSteps[LIMIT+ 1] = {0};
    uint64_t longest = 0;
    uint64_t longestStart = 0;

    uint64_t current = 0;
    uint32_t steps = 0;
    for (size_t i = 2; i <= LIMIT; ++i) {
        steps = 0;
        current = i;
        while (current != 1) {
            if (current & 1) {
                current = (current * 3) + 1;
            } else {
                current /= 2;
            }
            
            ++steps;
            if (current <= LIMIT && aSteps[current] != 0) {
                steps += aSteps[current];
                break;
            }
        }

        aSteps[i] = steps;
        if (steps > longest) {
            longest = steps;
            longestStart = i;
        }
    }
    return longestStart;
}

int main() {
    uint64_t result = problem14();
    std::cout << result << "\n";
}