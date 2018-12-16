#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>

using bint = boost::multiprecision::cpp_int;
int main()
{
    int N, X;
    std::cin >> N >> X;
    std::vector<int> xs;
    for (int i = 0; i < N; i++) {
        int x;
        std::cin >> x;
        xs.emplace_back(x);
    }
    bint result = 0;

    // ゴミを拾うエネルギー
    result += X * N;
    std::cout << result << std::endl;
    return 0;
}
