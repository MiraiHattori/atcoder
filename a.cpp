#include <iostream>

int main()
{
    int A, B, C, S;
    std::cin >> A >> B >> C >> S;
    if (A + B + C <= S and S <= A + B + C + 3) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
