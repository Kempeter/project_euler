#include <iostream>
#include <vector>

#include "Timer.h"

int problem16() {
    int sum = 0;
    int start = 2;
    std::vector<int> nums(1, start); 
    {
        Timer timer;
        for (int i = 1; i < 1000; ++i) {

            int carry = 0;
            for (size_t j = 0; j < nums.size(); ++j) {
                int n = nums[j] * start + carry;
                nums[j] = n % 10;
                carry = n / 10;

            }
            if (carry >= 10) {
                std::cout << carry << "\n";
            }

            while (carry > 0) {
                nums.push_back(carry % 10);
                carry /= 10;
            }
                
        }

        for (const int& i : nums) {
            sum += i;

        }
    }
    
    return sum;
}

int main() {
    int result = problem16();
    std::cout << result << "\n";
}