#include <iostream>
#include <vector>

int main()
{
    int N, M, A, B;
    std::cin >> N >> M >> A >> B;
    std::vector<int> ls, rs;
    for (int i = 0; i < M; i++) {
        int l, r;
        std::cin >> l >> r;
        ls.emplace_back(l);
        rs.emplace_back(r);
    }
    std::vector<bool> is_a(N, false);
    for (int i = 0; i < M; i++) {
        for (int j = ls.at(i) - 1; j <= rs.at(i) - 1; j++) {
            is_a.at(j) = true;
        }
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (is_a.at(i) ? A : B);
    }
    std::cout << sum << std::endl;
    return 0;
}
