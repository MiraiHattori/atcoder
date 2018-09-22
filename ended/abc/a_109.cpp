#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    if (a % 2 == 0 or b % 2 == 0) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
    return 0;
}
