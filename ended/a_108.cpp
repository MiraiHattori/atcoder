#include <iostream>
#include <string>
int main()
{
    int K;
    std::cin >> K;
    int a = K % 2;
    int b = K / 2;
    if (a == 0) {
        std::cout << b * b << std::endl;
    } else {
        std::cout << b * (b + 1) << std::endl;
    }
    return 0;
}
