#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using bint = boost::multiprecision::cpp_int;
int main()
{
    bint N, K;
    std::cin >> N >> K;
    // 全部Kの倍数
    bint n_k = N / K;
    bint ans = 0;
    // aaa
    if (n_k >= 1) {
        ans += n_k;
    }
    // aab
    if (n_k >= 2) {
        ans += 3 * n_k * (n_k - 1);
    }
    // abc
    if (n_k >= 3) {
        ans += n_k * (n_k - 1) * (n_k - 2);
    }
    if (K % 2 != 0) {
        std::cout << ans << std::endl;
    } else {
        bint n_k;
        if (N - K / 2 >= K) {
            n_k = (N - K / 2) / K + 1;
        } else if (N - K / 2 >= 0) {
            n_k = 1;
        } else {
            n_k = 0;
        }

        // aaa
        if (n_k >= 1) {
            ans += n_k;
        }
        // aab
        if (n_k >= 2) {
            ans += 3 * n_k * (n_k - 1);
        }
        // abc
        if (n_k >= 3) {
            ans += n_k * (n_k - 1) * (n_k - 2);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
