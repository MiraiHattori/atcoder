#include <algorithm>
#include <iostream>
#include <vector>
int main()
{
    int N, M, X, Y;
    std::cin >> N >> M >> X >> Y;
    std::vector<int> xs{};
    std::vector<int> ys{};
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        xs.emplace_back(x);
    }
    for (int i = 0; i < M; i++) {
        int y;
        std::cin >> y;
        ys.emplace_back(y);
    }
    std::sort(xs.begin(), xs.end());
    std::sort(ys.begin(), ys.end());
    if (X < Y and xs.at(xs.size() - 1) < ys.at(0) and xs.at(xs.size() - 1) < Y and X < ys.at(0)) {
        std::cout << "No War" << std::endl;
    } else {
        std::cout << "War" << std::endl;
    }
    return 0;
}
