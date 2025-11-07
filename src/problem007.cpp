#include <iostream>
#include <stdint.h>
#include <math.h>

bool sqrt_num(uint64_t primes[], uint64_t num, int idx) {

    for (int i = 0; i < idx; i++) {
        if (num % primes[i] == 0) {
            return false;
        }
    }

    return true;

}

uint64_t problem7() {
    int found = 3;
    uint64_t num = 5;
    uint64_t primes[10001] = { 2, 3, 5 };

    for (int i = 3; i < 10001; ++i) {
        primes[i] = (std::numeric_limits<uint64_t>::max)();
    }


    while (found <= 10000) {
        num += 2;

        uint64_t point = (uint64_t)sqrt(num);
        auto index = std::upper_bound(std::begin(primes), std::end(primes), point);
        int idx = std::distance(std::begin(primes), index);

        if (sqrt_num(primes, num, idx) == true) {
                found++;
                primes[found - 1] = num;
        }
    }

    return primes[sizeof(primes) / sizeof(primes[0]) - 1];
}


int main() {
    uint64_t result = problem7();
    std::cout << result << "\n";
}