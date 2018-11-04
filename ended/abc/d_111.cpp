#include <boost/multiprecision/cpp_int.hpp>
#include <cmath>
#include <iostream>
#include <vector>

using bint = boost::multiprecision::cpp_int;

bint power(const int& p, const int& q)
{
    bint result = 1;
    for (int i = 0; i < q; i++) {
        result *= p;
    }
    return result;
}

// bitを小さい位から32桁vectorに詰める
std::vector<int> getBits(const bint& num)
{
    std::vector<int> result{};
    for (int i = 0; i < 32; i++) {
        result.emplace_back(boost::multiprecision::bit_test(num, i));
    }
    return result;
}

int main()
{
    int N;
    std::vector<int> xs;
    std::vector<int> ys;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        xs.emplace_back(x);
        ys.emplace_back(y);
    }
    bool is_odd;
    if (std::abs(xs.at(0) + ys.at(0)) % 2 == 1) {
        is_odd = true;
    } else {
        is_odd = false;
    }
    for (int i = 0; i < N; i++) {
        if (is_odd and (xs.at(i) + ys.at(i)) % 2 == 0) {
            std::cout << -1 << std::endl;
            return 0;
        } else if (not is_odd and std::abs(xs.at(i) + ys.at(i)) % 2 == 1) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }
    if (not is_odd) {
        std::cout << 32 << std::endl;
        for (int i = 0; i < 31; i++) {
            std::cout << power(2, i) << " ";
        }
        std::cout << 1 << std::endl;
    } else {
        std::cout << 31 << std::endl;
        for (int i = 0; i < 30; i++) {
            std::cout << power(2, i) << " ";
        }
        std::cout << power(2, 30) << std::endl;
    }

    for (int i = 0; i < N; i++) {
        int x = xs.at(i);
        int y = ys.at(i);
        // 偶数なら左に一つずらす
        if (not is_odd) {
            x--;
        }
        bint sum_x_plus_y = (power(2, 31) - 1 + x + y) / 2;
        bint sum_x_minus_y = (power(2, 31) - 1 + x - y) / 2;
        std::vector<int> x_plus_y_bits = getBits(sum_x_plus_y);
        std::vector<int> x_minus_y_bits = getBits(sum_x_minus_y);
        for (int j = 0; j < 31; j++) {
            if (x_plus_y_bits.at(j) == 0 and x_minus_y_bits.at(j) == 0) {
                std::cout << "L";
            } else if (x_plus_y_bits.at(j) == 0 and x_minus_y_bits.at(j) == 1) {
                std::cout << "D";
            } else if (x_plus_y_bits.at(j) == 1 and x_minus_y_bits.at(j) == 0) {
                std::cout << "U";
            } else if (x_plus_y_bits.at(j) == 1 and x_minus_y_bits.at(j) == 1) {
                std::cout << "R";
            } else {
                std::cout << x_plus_y_bits.at(j) << " " << x_minus_y_bits.at(j) << std::endl;
                std::cerr << "error" << std::endl;
            }
        }
        if (not is_odd) {
            std::cout << "R" << std::endl;
        } else {
            std::cout << std::endl;
        }
    }


    return 0;
}
