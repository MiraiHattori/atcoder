#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> three_cand{};
    std::vector<int> five_cand{};
    std::vector<int> fifteen_cand{};
    std::vector<int> twenty_five_cand{};
    // 100 / 2
    for (int i : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}){
        if (N >= i * 2) {
            three_cand.emplace_back(i);
        }
    }
    if (N >= 6) {
        five_cand.emplace_back(2);
    }
    if (N >= 9) {
        five_cand.emplace_back(3);
    }
    // 100 / 4
    for (int i : {5, 7, 11, 13, 17, 19, 23}) {
        if (N >= i * 4) {
            five_cand.emplace_back(i);
        }
    }
    if (N >= 16) {
        fifteen_cand.emplace_back(2);
    }
    if (N >= 30) {
        fifteen_cand.emplace_back(3);
    }
    if (N >= 60) {
        fifteen_cand.emplace_back(5);
    }
    if (N >= 91) {
        fifteen_cand.emplace_back(7);
    }
    if (N >= 28) {
        twenty_five_cand.emplace_back(2);
    }
    if (N >= 54) {
        twenty_five_cand.emplace_back(3);
    }
    if (N >= 100) {
        twenty_five_cand.emplace_back(5);
    }

    int ans = 0;
    // 3 5 5
    for (const auto& th : three_cand) {
        for (const auto& fi : five_cand) {
            if (th != fi) {
                for (const auto& fi2 : five_cand) {
                    if (th != fi2 and fi < fi2) {
                        ans++;
                    }
                }
            }
        }
    }
    // 25 3
    for (const auto& tw : twenty_five_cand) {
        for (const auto& th : three_cand) {
            if (tw != th) {
                ans++;
            }
        }
    }
    // 15 5
    for (const auto& fif : fifteen_cand) {
        for (const auto& fi : five_cand) {
            if (fif != fi) {
                ans++;
            }
        }
    }
    // 75
    if (N >= 78) {
        ans++;
    }
    for (const auto& a : three_cand) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    for (const auto& a : five_cand) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    for (const auto& a : fifteen_cand) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    for (const auto& a : twenty_five_cand) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    std::cout << ans << std::endl;
    return 0;
}
