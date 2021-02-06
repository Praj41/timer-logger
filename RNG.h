#include <iostream>
#include <chrono>
#include <random>

unsigned int* RNG(unsigned int nos = 10, int min = 0, int max = 1000) {

    std::random_device rd;

    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch()
                    ).count() +
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(min, max);

    auto *arr = new unsigned int[nos];

    for (unsigned int j = 0; j < nos; ++j)
    {
        arr[j] = distrib(gen);
    }

    std::cout << '\n';
    return arr;
}

unsigned int RNG_s(int min = 0, int max = 1000) {

    std::random_device rd;

    std::mt19937::result_type seed = rd() ^ (
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::seconds>(
                            std::chrono::system_clock::now().time_since_epoch()
                    ).count() +
            (std::mt19937::result_type)
                    std::chrono::duration_cast<std::chrono::microseconds>(
                            std::chrono::high_resolution_clock::now().time_since_epoch()
                    ).count() );

    std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned> distrib(min, max);

    std::cout << '\n';
    return distrib(gen);
}
