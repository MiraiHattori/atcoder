#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>

using bint = boost::multiprecision::cpp_int;

int N, K;
std::vector<bint> as;
std::vector<int> zero_limits{};
bint answer = 0;

int zeroLimit(const bint& num_)
{
    int result = 0;
    bint num = num_;
    while (true) {
        if (num == 0) {
            break;
        }
        result++;
        num /= 2;
    }
    return result;
}


bint add(const bint& ans, const bint& val)
{
    return (ans + val) % 1000000007;
}


std::vector<std::vector<std::vector<bint>>> dp;

int main()
{
    std::cin >> N >> K;
    dp = std::vector<std::vector<std::vector<bint>>>(N + 1,
        std::vector<std::vector<bint>>(60 * N + 1, std::vector<bint>(2, 0)));

    for (int i = 0; i < N; i++) {
        bint a;
        std::cin >> a;
        as.emplace_back(a);
    }
    std::sort(as.begin(), as.end());
    for (int i = 0; i < N; i++) {
        zero_limits.emplace_back(zeroLimit(as.at(i)));
    }

    dp.at(1).at(1).at(0) = 1;
    dp.at(1).at(1).at(1) = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 60 * N; j++) {
            for (int k = j - zero_limits.at(i - 1) + 1; k <= j; k++) {
                if (k >= 0) {
                    dp.at(i).at(j).at(0) = add(dp.at(i).at(j).at(0), dp.at(i - 1).at(k).at(0));
                }
            }
            for (int k = j - zero_limits.at(i - 1); k <= j; k++) {
                if (k >= 0) {
                    dp.at(i).at(j).at(1) = add(dp.at(i).at(j).at(1), dp.at(i - 1).at(k).at(1));
                }
            }
            if (j - zero_limits.at(i - 1) >= 0) {
                dp.at(i).at(j).at(1) = add(dp.at(i).at(j).at(1), dp.at(i).at(j - zero_limits.at(i - 1)).at(0));
            }
        }
    }

    answer = add(answer, dp.at(N).at(K).at(0));

    for (int i = 0; i <= K; i++) {
        answer = add(answer, dp.at(N).at(i).at(1));
    }

    std::cout << answer << std::endl;

    return 0;
}
