#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct Point {
    int i;
    int a;
    int b;
};
int main()
{
    int N;
    std::cin >> N;
    std::vector<Point> ps{};
    for (int i = 0; i < N; i++) {
        Point p;
        int a, b;
        std::cin >> a >> b;
        p.i = i;
        p.a = a;
        p.b = b;
        ps.emplace_back(p);
    }
    int a_min = std::distance(ps.begin(), std::min_element(ps.begin(), ps.end(), [](auto a, auto b) { return a.a < b.a; }));
    int first_index = a_min;
    int first_b = ps.at(a_min).b;
    unsigned long long answer = 0;

    while (ps.size() > 1) {
        ps.erase(ps.begin() + first_index);
        std::sort(ps.begin(), ps.end(), [](auto a, auto b) { return a.a < b.a; });
        Point p = ps.at(first_index);
        auto it = std::lower_bound(ps.begin(), ps.end(), p, [](auto a, auto b) { return a.a < b.a; });
        int next_index = ps.size() - std::distance(ps.begin(), it) - 1;
        answer += std::min(ps.at(first_index).a, ps.at(next_index).b);
        std::cout << std::min(ps.at(first_index).a, ps.at(next_index).b) << std::endl;
    }
    answer += std::min(first_b, ps.at(first_index).a);
    std::cout << answer << std::endl;

    return 0;
}
