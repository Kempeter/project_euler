#include <iostream>
#include <vector>

int problem1() {
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
		
        return sum;
    }

int main() {
    int sum = problem1();

    std::cout << sum << "\n";
}