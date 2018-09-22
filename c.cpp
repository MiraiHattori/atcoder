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

long long int comb(long long int N, long long int K)
{
    if (N == 0 or K == 0) {
        return 0;
    }
    std::vector<std::vector<long long int>> v(N + 1, std::vector<long long int>(N + 1, 0));
    for (std::size_t i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (std::size_t k = 1; k < v.size(); k++) {
        for (std::size_t j = 1; j < k; j++) {
            v[k][j] = (v[k - 1][j - 1] + v[k - 1][j]);
        }
    }
    return v[N][K];
}

// i is N itr num
void dfs(int i, int rest)
{
    if (i == N - 1) {
        answer = add(answer, 1);
        return;
    }
    for (int j = 0; j <= K; j++) {
        if (j == 0) {
            answer = add(answer, 1);
        }
        if (j <= zero_limits.at(i + 1)) {
            answer = add(answer, comb(zero_limits.at(i + 1) + j - 1, j));
        } else if (zero_limits.at(i + 1) + 1 <= j) {
            dfs(i + 1, j);
        }
    }
}

int main()
{
    std::cin >> N >> K;
    for (int i = 0; i < N; i++) {
        bint a;
        std::cin >> a;
        as.emplace_back(a);
    }
    std::sort(as.begin(), as.end());
    for (int i = 0; i < N; i++) {
        zero_limits.emplace_back(zeroLimit(as.at(i)));
    }

    dfs(0, K);
    std::cout << answer % 1000000007 << std::endl;


    return 0;
}
