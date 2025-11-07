#include <iostream>

int problem5() {
    bool found = false;
    int start = 21;

    while (found == false) {
        start++;
        if (start - ((start / 10) * 10) != 0) {
            continue;
        }
        for (int i = 1; i <= 20; i++) {
            if (start % i != 0) {
                break;
            }
            else if (start % i == 0 && i == 20){
                found = true;
                return start;
            }
        }
    }
    return -1;
}

int main() {
    int result = problem5();
    std::cout << result << "\n";
}