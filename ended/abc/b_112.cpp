#include <iostream>
#include <limits>
#include <vector>

int main()
{
    int N, T;
    std::cin >> N >> T;
    std::vector<int> cs;
    std::vector<int> ts;
    for (int i = 0; i < N; i++) {
        int c, t;
        std::cin >> c >> t;
        cs.emplace_back(c);
        ts.emplace_back(t);
    }
    bool tle = true;
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < N; i++) {
        int t = ts.at(i);
        int c = cs.at(i);
        if (t <= T) {
            tle = false;
            if (min > c) {
                min = c;
            }
        }
    }
    if (tle) {
        std::cout << "TLE" << std::endl;
    } else {
        std::cout << min << std::endl;
    }
    return 0;
}
