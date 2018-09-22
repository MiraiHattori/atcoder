#include <iostream>
#include <vector>
#include <array>

int main()
{
    std::vector<std::array<int, 4>> moves;
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> board;
    for (int i = 0; i < h; i++) {
        std::vector<int> row;
        std::vector<bool> row_used;
        for (int j = 0; j < w; j++) {
            int p;
            std::cin >> p;
            row.emplace_back(p % 2);
        }
        board.emplace_back(row);
    }

    // 上から攻める
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w; j++) {
            if (board.at(i).at(j) == 1) {
                moves.emplace_back(std::array<int, 4>({i + 1, j + 1, i + 2, j + 1}));
                board.at(i).at(j) = 0;
                board.at(i + 1).at(j) = (board.at(i + 1).at(j) + 1) % 2;
            }
        }
    }
    // 最終段を左から攻める
    int buf;
    bool rest = false; // 1が余っているか
    for (int j = 0; j < w; j++) {
        if (board.at(h - 1).at(j) == 1) {
            if (rest) {
                for (int k = buf; k < j; k++) {
                    moves.emplace_back(std::array<int, 4>({h, k + 1, h, k + 2}));
                    board.at(h - 1).at(k) = 0;
                }
                board.at(h - 1).at(j) = 0;
                buf = -1; // error check
                rest = false;
            } else {
                buf = j;
                rest = true;
            }
        }
    }
    std::cout << moves.size() << std::endl;
    for (const auto& move : moves) {
        std::cout << move[0] << " " << move[1] << " " << move[2] << " " << move[3] << std::endl;
    }
    return 0;
}
