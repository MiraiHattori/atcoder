#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> xs;
    std::vector<int> ys;
    std::vector<int> hs;
    for (int i = 0; i < N; i++) {
        int x, y, h;
        std::cin >> x >> y >> h;
        xs.emplace_back(x);
        ys.emplace_back(y);
        hs.emplace_back(h);
    }
    for (int cx = 0; cx <= 100; cx++) {
        for (int cy = 0; cy <= 100; cy++) {
            int p = 0;
            bool tmp = false;
            while (true) {
                if (p > N - 1) {
                    tmp = true;
                    break;
                }
                if (hs.at(p) > 0) {
                    break;
                }
                p++;
            }
            if (tmp) {
                continue;
            }
            int H = hs.at(p) + std::abs(xs.at(p) - cx) + std::abs(ys.at(p) - cy);
            bool flag = true;
            for (int i = 0; i < N; i++) {
                if (std::max({H - std::abs(xs.at(i) - cx) - std::abs(ys.at(i) - cy), 0}) != hs.at(i)) {
                    flag = false;
                }
            }
            if (flag) {
                std::cout << cx << " " << cy << " " << H << std::endl;
            }
        }
    }
    return 0;
}
