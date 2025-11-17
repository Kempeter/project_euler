#include <iostream>
#include <stdint.h>

#include "Timer.h"

uint64_t problem3() {
    Timer timer;
    uint64_t num = 600851475143;
    uint64_t divisor = 1;

    while (num != 1) {

            divisor += 2;
            while (num % divisor == 0) {
                    num /= divisor;
            }
    }
    return divisor;
}

int main() {
    uint64_t divisor = problem3();
    std::cout << divisor << "\n";
}