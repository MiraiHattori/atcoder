#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

int getGcd(int a, int b) {
    std::vector<int> po({a, b});
    int bigger = *std::max_element(po.begin(), po.end());
    int smaller = *std::min_element(po.begin(), po.end());
    while (bigger % smaller != 0) {
        int tmp;
        tmp = bigger % smaller;
        std::vector<int> po2({smaller, tmp});
        int bigger2 = *std::max_element(po2.begin(), po2.end());
        int smaller2 = *std::min_element(po2.begin(), po2.end());
        bigger = bigger2;
        smaller = smaller2;
    }
    return smaller;
}


int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int> xs;
    for (int i = 0; i < n; i++) {
        int x_i;
        std::cin >> x_i;
        xs.emplace_back(x_i);
    }
    for (int i = 0; i < n; i++) {
        xs[i] -= x;
        xs[i] = std::abs(xs[i]);
    }
    int gcd = xs.at(0);
    for (int i = 1; i < n; i++) {
        gcd = getGcd(gcd, xs.at(i));
    }
    std::cout << gcd << std::endl;

    return 0;
}
