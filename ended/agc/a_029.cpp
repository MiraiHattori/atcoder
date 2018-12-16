#include <iostream>
#include <string>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
int main()
{
    std::string S;
    std::cin >> S;
    boost::multiprecision::cpp_int ans = 0;

    boost::multiprecision::cpp_int bs = 0;
    for (size_t i = 0; i < S.size(); i++) {
        if (S.at(i) == 'B') {
            bs++;
        } else {
            ans += bs;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}
