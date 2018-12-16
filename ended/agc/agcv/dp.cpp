#include <iostream>
#include <vector>
// 入力

int main()
{
    int N, x;
    std::cin >> N >> x;
    std::vector<int> w(N);
    std::vector<int> v(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int a_;
        std::cin >> a_;
        w.at(i) = a_;
        v.at(i) = 1;
        sum += a_;
    }
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(x + 1, 0));

    if (sum < x) {
        std::cout << N - 1 << std::endl;
        return 0;
    } else if (sum == x) {
        std::cout << N << std::endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= x; j++) {
            if (j >= w[i])
                dp[i + 1][j] = std::max(dp[i][j - w[i]] + v[i], dp[i][j]);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    std::cout << dp[N][x] << std::endl;
    return 0;
}
