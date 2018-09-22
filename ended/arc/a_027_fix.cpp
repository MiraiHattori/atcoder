#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <numeric>
#include <vector>

using bint = boost::multiprecision::cpp_int;

int main()
{
    int N, x;
    std::cin >> N >> x;
    std::vector<bint> a;
    for (int i = 0; i < N; i++) {
        bint a_;
        std::cin >> a_;
        a.emplace_back(a_);
    }
    bint max = 0;
    for (const auto& a_e : a) {
        max += a_e;
    }
    if (max == x) {
        std::cout << N << std::endl;
        return 0;
    }

    std::sort(a.begin(), a.end());
    bint sum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        sum += a.at(i);
        if (sum > x) {
            break;
        }
        ans = i + 1;
    }
    if (ans == N) {
        ans = N - 1;
    }
    std::cout << ans << std::endl;
    return 0;
}
