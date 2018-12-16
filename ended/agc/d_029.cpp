#include <bits/stdc++.h>

int main()
{
    int H, W, N;
    std::cin >> H >> W >> N;
    std::vector<std::vector<int>> board(H + 1, std::vector<int>{});
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        board.at(x).emplace_back(y);
    }
    int width = 1;
    for (int i = 1; i < H; i++) {
        std::vector<int> row = board.at(i + 1);
        bool has_end = false;
        for (const auto& r : row) {
            if (r == width + 1) {
                has_end = true;
            }
            if (r <= width) {
                std::cout << i << std::endl;
                return 0;
            }
        }
        if (not has_end) {
            width++;
        }
    }
    std::cout << H << std::endl;
    return 0;
}
