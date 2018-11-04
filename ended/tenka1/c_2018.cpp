#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> as{};
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        as.emplace_back(a);
    }
    std::sort(as.begin(), as.end());

    auto max_itr = std::max_element(as.begin(), as.end());
    int max = *max_itr;
    as.erase(max_itr);
    auto min_itr = std::min_element(as.begin(), as.end());
    int min = *min_itr;
    as.erase(min_itr);

    std::vector<int> ans{{min, max}};
    for (int i = 0; i < N - 2; i++) {
        int max_diff = -1;
        int choice = -1;  // 0~3
        if (std::abs(as.at(as.size() - 1) - ans.at(0)) > max_diff) {
            max_diff = std::abs(as.at(as.size() - 1) - ans.at(0));
            choice = 0;
        }
        if (std::abs(as.at(as.size() - 1) - ans.at(ans.size() - 1)) > max_diff) {
            max_diff = std::abs(as.at(as.size() - 1) - ans.at(ans.size() - 1));
            choice = 1;
        }
        if (std::abs(as.at(0) - ans.at(0)) > max_diff) {
            max_diff = std::abs(as.at(0) - ans.at(0));
            choice = 2;
        }
        if (std::abs(as.at(0) - ans.at(ans.size() - 1)) > max_diff) {
            max_diff = std::abs(as.at(0) - ans.at(ans.size() - 1));
            choice = 3;
        }

        if (choice == 0) {
            ans.insert(ans.begin(), as.at(as.size() - 1));
            as.erase(as.begin() + as.size() - 1);
        } else if (choice == 1) {
            ans.emplace_back(as.at(as.size() - 1));
            as.erase(as.begin() + as.size() - 1);
        } else if (choice == 2) {
            ans.insert(ans.begin(), as.at(0));
            as.erase(as.begin() + 0);
        } else if (choice == 3) {
            ans.emplace_back(as.at(0));
            as.erase(as.begin() + 0);
        }
    }

    unsigned long long result = 0;
    for (int i = 0; i < N - 1; i++) {
        result += std::abs(ans.at(i) - ans.at(i + 1));
    }
    std::cout << result << std::endl;

    return 0;
}
