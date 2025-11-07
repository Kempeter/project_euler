#include <iostream>

int problem2() {
    int sum = 0;
    int x = 1;
    int y = 1;
    int now = 1;

    while (now < 4000000) {
            now = x + y;

            if (now % 2 == 0) {
                    sum += now;
            }

            x = y;
            y = now;
    }

    return sum;
}

int main() {
    int sum = problem2();
    std::cout << sum << "\n";
    return 0;
}