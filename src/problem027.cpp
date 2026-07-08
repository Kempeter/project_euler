#include <iostream>
#include <cmath>
#include "Timer.h"


bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= std::sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

int problem27() {
    Timer timer;
    int la, lb, longest = 0;

    for (int a = -999; a < 1000; a++) {
        for (int b = 3; b < 1000; b += 2) {
            int n = 0;

            bool bPrime = true;
            int length = 0;
            while (bPrime)
            {
                int quad = std::pow(n, 2) + a*n + b;
                bPrime = isPrime(quad);
                if (bPrime) {
                    length++;
                    n++;
                }
            }

            if (length > longest) {
                la = a;
                lb = b;
                longest = length;
            }
            
        }
    }
    
    return la * lb;
}

int main() {
    int result = problem27();
    std::cout << result << "\n";
}