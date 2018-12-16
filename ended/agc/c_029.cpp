#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <utility>

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
    int ans = 0;
    std::map<int, int> index_and_num{};
    int last;
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            ans++;
        } else {
            if (last >= as.at(i)) {
                std::map<int, int>::iterator it = index_and_num.find(as.at(i));
                if (it == index_and_num.end()) {
                    index_and_num.insert(std::make_pair<int, int>(static_cast<int&&>(as.at(i)), 1));
                    if (ans < 2) {
                        ans = 2;
                    }
                } else {
                    (*it).second++;
                    while (true) {
                        if (it == index_and_num.begin()) {
                            break;
                        }
                        if ((*std::prev(it, 1)).second >= (*it).second) {
                            break;
                        } else {
                            (*it).second = 1;
                            (*std::prev(it, 1)).second++;
                            it = std::prev(it, 1);
                        }
                    }
                    if ((*it).second + 2 > ans) {
                        ans = (*it).second + 2;
                    }
                }
            } else {
                // std::sort(index_and_num.begin(), index_and_num.end(), [] (auto a, auto b) {a.first < b.first;});
                index_and_num.erase(index_and_num.upper_bound(as.at(i)), index_and_num.end());
            }
        }
        last = as.at(i);
    }
    std::cout << ans << std::endl;
    return 0;
}
