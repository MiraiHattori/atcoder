#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> ps{};
    for (int i = 0; i < N; i++) {
        int p;
        std::cin >> p;
        ps.emplace_back(p);
    }
    std::cout << std::accumulate(ps.begin(), ps.end(), 0) - (*std::max_element(ps.begin(), ps.end())) / 2 << std::endl;

    return 0;
}
