#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    int N, X;
    std::cin >> N >> X;
    std::vector<int> as;
    std::vector<int> bs;
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        as.emplace_back(a);
        bs.emplace_back(b);
    }
    int index = std::distance(bs.begin(), std::max_element(bs.begin(), bs.end()));
    as.at(index) += X;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += as.at(i) * bs.at(i);
    }
    std::cout << ans << std::endl;
    return 0;
}
