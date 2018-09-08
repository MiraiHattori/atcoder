#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using bint = boost::multiprecision::cpp_int;

std::size_t power(std::size_t num, std::size_t power)
{
    std::size_t result = 1;
    for (std::size_t i = 0; i < power; i++) {
        result *= num;
    }
    return result;
}

int main()
{
    bint L;
    std::cin >> L;
    std::vector<bint> bits;
    bint L_copy = L;
    while (true) {
        if (L_copy <= 1) {
            bits.emplace_back(L_copy);
            break;
        }
        bits.emplace_back(L_copy % 2);
        L_copy = (L_copy - L_copy % 2) / 2;
    }
    std::reverse(bits.begin(), bits.end());

    std::size_t N = bits.size();
    std::vector<std::array<std::size_t, 3>> ans_graphs;
    for (std::size_t i = 1; i < N; i++) {
        std::array<std::size_t, 3> graph1, graph2;
        graph1.at(0) = i;
        graph1.at(1) = i + 1;
        graph1.at(2) = 0;
        graph2.at(0) = i;
        graph2.at(1) = i + 1;
        graph2.at(2) = power(2, i - 1);
        ans_graphs.emplace_back(graph1);
        ans_graphs.emplace_back(graph2);
    }
    L_copy = L;
    for (std::size_t i = N - 1; i > 0; i--) {
        if (L_copy - power(2, N - 1) == 0) {
            break;
        }
        if (L_copy - power(2, N - 1) >= power(2, i - 1)) {
            std::array<std::size_t, 3> graph1;
            graph1.at(0) = i;
            graph1.at(1) = N;
            graph1.at(2) = static_cast<std::size_t>(L_copy - power(2, i - 1));
            L_copy -= power(2, i - 1);
            ans_graphs.emplace_back(graph1);
        }
    }

    std::cout << N << " " << ans_graphs.size() << std::endl;
    for (const auto& graph : ans_graphs) {
        std::cout << graph.at(0) << " " << graph.at(1) << " " << graph.at(2) << std::endl;
    }

    return 0;
}
