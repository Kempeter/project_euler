#include <iostream>
#include <fstream>
#include <stdint.h>
#include <string>
#include <algorithm>

#include "Timer.h"

uint64_t problem8(size_t length) {

    std::fstream file("data_files/problem008.txt");
    if (!file.is_open()) {
        std::cout << "Cannot open data file" << "\n";
        return 0;
    }

    std::string nums;
    std::string line;
    while (std::getline(file, line))
    {
        nums += line;
    }
    nums.erase(std::remove(nums.begin(), nums.end(), '\n'), nums.end());
    
    uint64_t sum = 0;
    
    {
        Timer timer;   
        for (size_t i = 0; i < nums.size(); i++) {
            if (i + length > nums.size()) {
                break;
            }

            uint64_t temp_sum = 1;
            for (size_t j = 0; j < length; j++) {
                temp_sum *= nums[i + j] - '0';
            }

            if (temp_sum > sum) {
                sum = temp_sum;
            }
        }
    }
return sum;
}

int main() {
    uint64_t result = problem8(13);
    std::cout << result << "\n";
}