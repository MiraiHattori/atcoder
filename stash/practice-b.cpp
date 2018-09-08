#include <iostream>
#include <string>
#include <vector>
#include <array>

char getChar(int i)
{
    char a = static_cast<char>(i + 'A');
    return a;
}


int main()
{
    int N, Q;
    std::cin >> N >> Q;
    std::vector<char> cs;
    for (int i = 0; i < Q; i++) {
        cs.emplace_back(getChar(i));
    }
    for (int i = 0; i < Q; i++) {
        int i1 = 0, i2 = 0;
        char c;
        std::cout << "? " << cs.at(i1) << " " << cs.at(i2) << std::endl;
        std::cin >> c;
        switch (c) {
        case '>':
            break;
        case '<':
            break;
        default:
            std::cerr << "error " << c << std::endl;
            break;
        }
    }
    std::cout << "! ";
    for (int i = 0; i < Q; i++) {
        std::cout << cs.at(i);
    }
    std::cout << std::endl;
    return 0;
}
