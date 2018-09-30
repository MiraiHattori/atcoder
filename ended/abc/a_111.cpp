#include <iostream>

int main()
{
    std::string n;
    std::cin >> n;
    std::string s = "";
    for (const auto& c : n) {
        if (c == '1') {
            s.push_back('9');
        } else {
            s.push_back('1');
        }
    }
    std::cout << s << std::endl;
    return 0;
}
