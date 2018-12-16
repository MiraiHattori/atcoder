#include <iostream>
int main()
{
    int N;
    std::cin >> N;
    if (N == 25) {
        std::cout << "Christmas" << std::endl;
    } else if (N == 24) {
        std::cout << "Christmas Eve" << std::endl;
    } else if (N == 23) {
        std::cout << "Christmas Eve Eve" << std::endl;
    } else if (N == 22) {
        std::cout << "Christmas Eve Eve Eve" << std::endl;
    }
    return 0;
}
