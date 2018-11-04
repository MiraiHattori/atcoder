#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    int cross_start_idx = 0;
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            cross_start_idx += 2;
            cross_start_idx %= 5;
        }
        for (int j = 0; j < N; j++) {
            if (j % 5 == cross_start_idx) {
                std::cout << "X";
            } else if (i == 0) {
                if (j % 5 == 3) {
                    std::cout << "X";
                } else if (j == 0) {
                    std::cout << "X";
                } else if (j == N - 1) {
                    std::cout << "X";
                } else {
                    std::cout << ".";
                }
            } else if (j == 0) {
                if (i % 5 == 2) {
                    std::cout << "X";
                } else if (i == 0) {
                    std::cout << "X";
                } else if (i == N - 1) {
                    std::cout << "X";
                } else {
                    std::cout << ".";
                }
            } else if (i == N - 1) {
                if ((j + 3) % 5 == cross_start_idx) {
                    std::cout << "X";
                } else if (j == 0) {
                    std::cout << "X";
                } else if (j == N - 1) {
                    std::cout << "X";
                } else {
                    std::cout << ".";
                }
            } else if (j == N - 1) {
                if (N % 5 == cross_start_idx) {
                    std::cout << "X";
                } else if (i == 0) {
                    std::cout << "X";
                } else if (i == N - 1) {
                    std::cout << "X";
                } else {
                    std::cout << ".";
                }
            } else {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
