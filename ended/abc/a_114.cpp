#include <iostream>
int main()
{
    int X;
    std::cin >> X;
    if (X == 3 or X == 5 or X == 7) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
