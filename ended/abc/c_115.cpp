#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
int main()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> hs{};
    for (int i = 0; i < N; i++) {
        int h;
        std::cin >> h;
        hs.emplace_back(h);
    }
    std::sort(hs.begin(), hs.end());
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < N - K + 1; i++) {
        if (hs.at(i + K - 1) - hs.at(i) < min) {
            min = hs.at(i + K - 1) - hs.at(i);
        }
    }
    std::cout << min << std::endl;
    return 0;
}
