#include <boost/multiprecision/cpp_int.hpp>
#include <array>
#include <iostream>
#include <vector>
using bint = boost::multiprecision::cpp_int;



int main()
{
    std::array<bint, 53> powers{};
    powers.at(0) = 1;
    for (int i = 1; i <= 52; i++) {
        powers.at(i) = 2 * powers.at(i - 1);
    }
    int N;
    bint X;
    std::cin >> N >> X;

    bint ans = 0;
    for (int i = N; i >= 0; i--) {
        if (i != 0) {
            bint div = X / (powers.at(i + 2) - 3);
            bint mod = X % (powers.at(i + 2) - 3);
            ans += div * (powers.at(i + 1) - 1);
            X = mod;
            if (X >= powers.at(i + 2) - 3) {
                ans++;
                X -= 3; // remove BPB
            } else if (X >= powers.at(i + 1) - 1) {
                X -= 2; // remove PB
                ans++;
            } else if (X >= 1) {
                X -= 1;
            }
        } else {
            if (X == 1) {
                ans++;
            } else if (X == 2) {
                ans += 2;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}
