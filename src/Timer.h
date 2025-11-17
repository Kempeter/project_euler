#include <chrono>
#include <iostream>

struct Timer
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<double> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        std::cout << "Timer took: " << duration.count() * 1000.0f << "ms" << "\n";
    }
};
