#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <stdint.h>
#include <assert.h>

std::string problem13(std::array<std::array<uint8_t, 50>, 100>& data) {
    std::array<uint8_t, 53> sum = {0};

    for (size_t row = 0; row < data.size(); ++row) {

        uint8_t rem = 0;
        for (size_t i = 0; i < data[row].size(); ++i) {
            size_t temp = sum[i] + data[row][i] + rem;
            sum[i] = temp % 10;
            rem = temp / 10;
        }

        size_t j = data[row].size();
        while (rem != 0)
        {   
            uint8_t temp = sum[j] + rem;
            sum[j] = temp % 10;
            rem = temp / 10;
            ++j;
        }
        
    }
    
    int startIndex = sum.size() - 1;
    while (startIndex > 0 && sum[startIndex] == 0)
    {
        --startIndex;
    }
    
    std::string result;
    result.reserve(startIndex + 1);

    for (int i = startIndex; i > startIndex - 10; --i) {
        result += std::to_string(sum[i]);
    }

    return result;
}


int main() {

    std::fstream file("data_files/problem013.txt");
    if (!file.is_open()) {
        std::cout << "Error: Could not open file\n";
        return 1;
    }

    std::array<std::array<uint8_t, 50>, 100> data = {0};
    std::string line;
    size_t count = 0;
    while (std::getline(file, line))
    {
        for (size_t i = 0; i < line.size(); ++i) {
            data[count][i] = static_cast<uint8_t>(line[line.size() - i - 1] - '0');  
        }
        ++count;
    }

    std::string result = problem13(data);
    std::cout << "Result: " << result << "\n";
    assert(result == "5537376230");
    
}