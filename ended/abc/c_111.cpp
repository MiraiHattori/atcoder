#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

int ans = 0;
int main()
{
    int n;
    std::cin >> n;
    std::vector<int> v_odd;
    std::vector<int> v_even;
    std::vector<std::pair<int, int>> odd_l{};
    std::vector<std::pair<int, int>> even_l{};
    for (int i = 0; i < n / 2; i++) {
        int v1;
        std::cin >> v1;
        v_odd.emplace_back(v1);
        int v2;
        std::cin >> v2;
        v_even.emplace_back(v2);
    }
    for (const auto& v : v_odd) {
        bool is = false;
        for (auto& e : odd_l) {
            if (e.first == v) {
                e.second++;
                is = true;
                break;
            }
        }
        if (not is) {
            int v_ = v;
            odd_l.push_back(std::make_pair<int, int>(std::move(v_), 1));
        }
    }
    for (const auto& v : v_even) {
        bool is = false;
        for (auto& e : even_l) {
            if (e.first == v) {
                e.second++;
                is = true;
                break;
            }
        }
        if (not is) {
            int v_ = v;
            even_l.push_back(std::make_pair<int, int>(std::move(v_), 1));
        }
    }
    std::sort(odd_l.begin(), odd_l.end(), [](auto& a, auto& b) { return a.second > b.second; });
    std::sort(even_l.begin(), even_l.end(), [](auto& a, auto& b) { return a.second > b.second; });

    if (odd_l.at(0).first != even_l.at(0).first) {
        std::cout << n - odd_l.at(0).second - even_l.at(0).second << std::endl;
        return 0;
    }

    std::pair<int, int> a;
    a.first = -1;
    a.second = 0;
    if (odd_l.size() == 1) {
        odd_l.emplace_back(a);
    }
    if (even_l.size() == 1) {
        even_l.emplace_back(a);
    }

    if (odd_l.at(1).second + even_l.at(0).second > odd_l.at(0).second + even_l.at(1).second) {
        std::cout << n - odd_l.at(1).second - even_l.at(0).second << std::endl;
    } else {
        std::cout << n - odd_l.at(0).second - even_l.at(1).second << std::endl;
    }

    return 0;
}
