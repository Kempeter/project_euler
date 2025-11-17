#include <iostream>
#include <vector>

#include "Timer.h"

int problem4() {
    Timer timer;
    //find palindromic
    int x = 999;
    int y = 999;
    int big = x * y;
    std::vector<int> nums;

    for (int i = big; i > 10000; i--) {
        int resultNumber = 0;
        for (int j = i; j != 0;) {
            int d = j / 10;
            resultNumber = (resultNumber - d) * 10 + j;
            j = d;
        }
        if (i == resultNumber) {
            nums.push_back(i);
        }
    }

    
    for (int i : nums) {
        for (int j = x; j > 99; j--) {
            if (i % j == 0 && i / j < 1000) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    int result = problem4();
    std::cout << result << "\n";
}