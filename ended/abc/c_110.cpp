// これは嘘解法
#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string S, T;
    std::cin >> S >> T;
    std::array<int, 46> al_s{};
    for (auto c : S) {
        al_s.at(c - 'a')++;
    }
    std::sort(al_s.begin(), al_s.end());
    std::reverse(al_s.begin(), al_s.end());
    std::array<int, 46> al_t{};
    for (auto c : T) {
        al_t.at(c - 'a')++;
    }
    std::sort(al_t.begin(), al_t.end());
    std::reverse(al_t.begin(), al_t.end());

    if (al_s == al_t) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    return 0;
}
