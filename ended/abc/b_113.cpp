#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    int T, A;
    std::cin >> T >> A;
    std::vector<double> vs{};
    for (int i = 0; i < N; i++) {
        int H;
        std::cin >> H;
        double v = std::abs(T - H * 0.006 - A);
        vs.emplace_back(v);
    }

    int i = std::distance(vs.begin(), std::min_element(vs.begin(), vs.end()));
    std::cout << i + 1 << std::endl;
    return 0;
}
