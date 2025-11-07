#include <iostream>
#include <vector>

void problem1() {
		std::vector<int> nums;
		int sum = 0;
		for (int i = 0; i < 1000; i++) {

				if (i % 3 == 0 || i % 5 == 0) {
						nums.push_back(i);
				}

		}

		for (const int& i : nums) {
				sum += i;
		}
		std::cout << sum;
    }