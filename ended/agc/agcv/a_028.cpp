#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>

using bint = boost::multiprecision::cpp_int;

bint gcdf(bint a, bint b)
{
    if (a < b) {
        std::swap(a, b);
    }
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}


int main()
{
    bint N, M;
    std::string S;
    std::string T;
    std::cin >> N >> M >> S >> T;
    bint gcd = gcdf(N, M);
    bint lcm = N * M / gcd;
    bint tmp = gcdf(lcm / N, lcm / M);
    bint tmpl = lcm / N * lcm / M / tmp;
    // std::cerr << lcm << std::endl;
    bool ok = true;
    for (bint i = 0; i < lcm; i += tmpl) {
        if (i % (lcm / N) == 0 and i % (lcm / M) == 0) {
            // std::cerr << i << std::endl;
            if (S.at(static_cast<int>(i / (lcm / N))) != T.at(static_cast<int>(i / (lcm / M)))) {
                ok = false;
            }
        }
    }
    if (ok) {
        std::cout << lcm << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }
    return 0;
}
