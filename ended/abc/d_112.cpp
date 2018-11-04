#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    unsigned long long N, M;
    std::cin >> N >> M;
    if (N == 1) {
        std::cout << M << std::endl;
        return 0;
    }

    std::vector<unsigned long long> big_yakusu{};
    for (unsigned long long i = 1; i <= std::floor(std::sqrt(M)) + 1; i++) {
        if (M % i == 0) {
            big_yakusu.emplace_back(M / i);
            if (i >= N) {
                std::cout << M / i << std::endl;
                return 0;
            }
        }
    }
    std::reverse(big_yakusu.begin(), big_yakusu.end());
    for (const auto& y : big_yakusu) {
        if (y >= N) {
            std::cout << M / y << std::endl;
            return 0;
        }
    }
    std::cout << 1 << std::endl;
    return 0;
}
