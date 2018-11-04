#include <iomanip>
#include <iostream>

int main()
{
    int m;
    std::cin >> m;
    if (m < 100.0) {
        std::cout << std::right << std::setw(2) << std::setfill('0') << 0 << std::endl;
    } else if (100.0 <= m and m <= 5000.0) {
        std::cout << std::right << std::setw(2) << std::setfill('0') << static_cast<int>(m / 100.0) << std::endl;
    } else if (6000.0 <= m and m <= 30000.0) {
        std::cout << std::right << std::setw(2) << std::setfill('0') << static_cast<int>(m / 1000.0 + 50.0) << std::endl;
    } else if (35000.0 <= m and m <= 70000.0) {
        std::cout << std::right << std::setw(2) << std::setfill('0') << static_cast<int>((m / 1000.0 - 30.0) / 5.0 + 80.0) << std::endl;
    } else {
        std::cout << std::right << std::setw(2) << std::setfill('0') << 89 << std::endl;
    }
}
