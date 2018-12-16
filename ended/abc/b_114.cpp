#include <iostream>
#include <string>
#include <cmath>
#include <limits>
int main()
{
    std::string S;
    std::cin >> S;

    int max = std::numeric_limits<int>::max();
    for (size_t i = 0; i < S.size() - 2; i++) {
        if (std::abs((S.at(i) - '0') * 100 + (S.at(i + 1) - '0') * 10 + (S.at(i + 2) - '0') - 753) < max) {
            max = std::abs((S.at(i) - '0') * 100 + (S.at(i + 1) - '0') * 10 + (S.at(i + 2) - '0') - 753);
        }
    }
    std::cout << max << std::endl;
    return 0;
}
