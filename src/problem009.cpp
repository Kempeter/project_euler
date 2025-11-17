#include <iostream>
#include <math.h>

#include "Timer.h"

int gcd(int x, int y) {

    while (x != 0 && y != 0) {
        if (x > y) {
            x = x % y;
        }
        else {
            y = y % x;
        }
    }

    if (x == 0) {
        return y;
    }
    else {
        return x;
    }
}

int problem9() {
    Timer timer;
    int s = 1000;
    int s2 = s / 2;
    int mlimit = sqrt(s2) - 1;

    for (int i = 2; i < mlimit; i++) {
        int k = 0;
        if (s2 % i == 0) {
            int sm = s2 / i;

            while (sm % 2 == 0) {
                sm = sm / 2;
            }

            if (i % 2 == 1) {
                k = i + 2;
            }
            else {
                k = i + 1;
            }

            while (k < 2 * i && k <= sm) {
                if (sm % k == 0 && gcd(k, i) == 1) {
                    int d = s2 / (k * i);
                    int n = k - i;
                    int a = d * (i * i - n * n);
                    int b = 2 * d * i * n;
                    int c = d * (i * i + n * n);

                    return a * b * c;
                }

                k = k + 2;
            }
        }
    }

    return -1;
}

int main() {
    int result = problem9();
    std::cout << result << "\n";
}