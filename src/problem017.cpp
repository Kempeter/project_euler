#include <iostream>
#include <unordered_map>

#include "Timer.h"

int problem17() {   
    Timer timer;
    std::unordered_map<int, int> u_map = {
        {1, 3},
        {2, 3},
        {3, 5},
        {4, 4},
        {5, 4},
        {6, 3},
        {7, 5},
        {8, 5},
        {9, 4},
        {10, 3},
        {11, 6},
        {12, 6},
        {13, 8},
        {14, 8},
        {15, 7},
        {16, 7},
        {17, 9},
        {18, 8},
        {19, 8},
        {20, 6},
        {30, 6},
        {40, 5},
        {50, 5},
        {60, 5},
        {70, 7},
        {80, 6},
        {90, 6},
        {100, 10},
        {200, 10},
        {300, 12},
        {400, 11},
        {500, 11},
        {600, 10},
        {700, 12},
        {800, 12},
        {900, 11},
        {1000, 11}
    };

    int sum = 0;
    int temp = 0;
    for (int i = 1; i < 1001; ++i) {
        if (i <= 20) {
            sum += u_map.at(i);
        }
        else if (i % 10 == 0 && i < 100) {
            sum += u_map.at(i);
        }
        else if (i % 100 == 0) {
            sum += u_map.at(i);
        }
        else if(i > 20 && i < 100) {
            sum += u_map.at((i / 10) * 10);
            sum += u_map.at(i % 10);
        }
        else if (i > 100 && i % 10 == 0) {
            sum += u_map.at((i / 100) * 100);
            sum += 3;
            sum += u_map.at(i % 100);
        }
        else if(i > 100 && i % 10 != 0) {
            sum += u_map.at((i / 100) * 100);
            sum += 3;
            temp = i % 100;
            if (temp <= 20) {
                sum += u_map.at(temp);
            }
            else {
                sum += u_map.at((temp / 10) * 10);
                sum += u_map.at(temp % 10);
            }
        }
    }
    return sum;
}

int main() {
    int result = problem17();
    std::cout << result << "\n";
}