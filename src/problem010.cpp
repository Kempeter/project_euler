#include <iostream>
#include <stdint.h>
#include <vector>
#include <math.h>

#include "Timer.h"

uint64_t eratosthenes(int limit) {
    Timer timer;
    int crosslimit = sqrt(limit);
    std::vector<bool> sieve(limit);

    std::fill(std::begin(sieve), std::end(sieve), false);

    for (int i = 4; i < limit; i += 2) {
        sieve[i] = true;
    }

    for (int i = 3; i < crosslimit; i += 2) {
        if (sieve[i] == false)
        {
            for (int j = i * i; j < limit; j += 2 * i) {
                sieve[j] = true;
            }
        }
    }

    uint64_t sum = 0;
    for (int i = 2; i < limit; i++)
    {
        if (sieve[i] == false) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    uint64_t result = eratosthenes(2000000);
    std::cout << result << "\n";
}