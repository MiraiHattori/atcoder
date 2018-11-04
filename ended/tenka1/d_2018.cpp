#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <functional>
#include <iostream>
#include <vector>


using bint = boost::multiprecision::cpp_int;


template <class T>
void combination(const std::vector<T>& seed, const int& target_size, std::vector<std::vector<int>>& ans)
{
    std::vector<int> indices(target_size);
    const int seed_size = seed.size();
    int start_index = 0;
    int size = 0;
    int ans_index = 1;
    while (size >= 0) {
        for (int i = start_index; i < seed_size; ++i) {
            indices[size++] = i;
            if (size == target_size) {
                std::vector<T> comb(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = seed[indices[x]];
                }
                ans.at(comb[0] - 1).emplace_back(ans_index);
                ans.at(comb[1] - 1).emplace_back(ans_index);
                ans_index++;
                break;
            }
        }
        size--;
        if (size < 0) {
            break;
        }
        start_index = indices[size] + 1;
    }
}


int main()
{
    int N;
    std::cin >> N;
    std::vector<int> applies{};
    bint n = 2;
    bint max = 1;
    for (int i = 0; i < 10; i++) {
        max *= 10;
    }
    while (true) {
        bint nC2 = n * (n - 1) / 2;
        if (nC2 > max) {
            break;
        }
        applies.emplace_back(nC2);
        n++;
    }
    auto it = std::find(applies.begin(), applies.end(), N);
    if (it == applies.end()) {
        std::cout << "No" << std::endl;
        return 0;
    }
    std::cout << "Yes" << std::endl;
    int k = std::distance(applies.begin(), it) + 2;
    std::cout << k << std::endl;
    std::vector<std::vector<int>> ans(k);
    std::vector<int> comb(k);
    for (int i = 0; i < k; i++) {
        comb.at(i) = i + 1;
    }
    combination<int>(comb, 2, ans);
    for (const auto& row : ans) {
        std::cout << row.size() << " ";
        for (const auto& col : row) {
            if (col != row.at(row.size() - 1)) {
                std::cout << col << " ";
            } else {
                std::cout << col << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
