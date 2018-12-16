#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

unsigned long long mod = 1000000007;
int main()
{
    int H, W, K;
    std::cin >> H >> W >> K;
    std::vector<unsigned long long> layers(W, 0);

    layers.at(0) = 1;
    // あみだくじ全通り
    std::vector<std::vector<bool>> amida(1, std::vector<bool>(W, false));
    for (int j = 1; j < W; j++) {
        std::vector<std::vector<bool>> last = amida;
        for (const auto& a : last) {
            if (not a.at(j - 1)) {
                std::vector<bool> to_add = a;
                to_add.at(j) = true;
                amida.emplace_back(to_add);
            }
        }
    }
    for (int i = 1; i <= H; i++) {
        std::vector<unsigned long long> layers_copy(W, 0);
        // i - 1からiへ
        for (const auto& a : amida) {
            for (int j = 0; j < W; j++) {
                if (j == 0) {
                    if (a.size() == 1 or not a.at(1)) {
                        layers_copy.at(j) += layers.at(j);
                    } else {
                        layers_copy.at(j) += layers.at(j + 1);
                    }
                } else if (j == W - 1) {  // 0だったら前のifに入る
                    if (a.at(j)) {
                        layers_copy.at(j) += layers.at(j - 1);
                    } else {
                        layers_copy.at(j) += layers.at(j);
                    }
                } else {
                    if (a.at(j)) {
                        layers_copy.at(j) += layers.at(j - 1);
                    } else if (a.at(j + 1)) {
                        layers_copy.at(j) += layers.at(j + 1);
                    } else {
                        layers_copy.at(j) += layers.at(j);
                    }
                }
                layers_copy.at(j) %= mod;
            }
        }
        layers = layers_copy;
    }
    std::cout << layers.at(K - 1) << std::endl;

    return 0;
}
