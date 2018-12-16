#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using bint = boost::multiprecision::cpp_int;
bint power(const int& pow)
{
    bint ans = 1;
    for (int i = 0; i < pow; i++) {
        ans *= 2;
    }
    return ans;
}


int main()
{
    std::vector<bint> pows{};
    for (int i = 0; i < 33; i++) {
        pows.emplace_back(power(i));
    }

    int N;
    std::cin >> N;
    std::vector<int> as{};
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        as.emplace_back(a);
    }
    int ans = 0;
    std::sort(as.begin(), as.end());
    while (as.size() > 0) {
        int s = as.at(as.size() - 1);
        as.pop_back();
        int upper_pow = -1;
        for (int i = 0; i < 33; i++) {
            if (s < power(i)) {
                upper_pow = i;
                break;
            }
        }
        int diff = static_cast<int>(power(upper_pow) - s);
        auto it = std::lower_bound(as.begin(), as.end(), diff);
        if (it != as.end() and *it == diff) {
            as.erase(it, it + 1);
            ans++;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
