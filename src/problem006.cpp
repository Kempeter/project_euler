#include <iostream>
#include <math.h>

#include "Timer.h"

int problem6() {
    Timer timer;
    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i <= 100; i++) {
        sum1 += pow(i, 2);
        sum2 += i;
    }
    sum2 = pow(sum2, 2);

    return sum2 - sum1;
}

int main() {
    int result = problem6();
    std::cout << result << "\n";
}
