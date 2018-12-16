#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<long long> all{};

void rec(long long val, bool three, bool five, bool seven, int num) {
    if (val > 1000000000 or val > num) {
        return;
    }
    if (three and five and seven) {
        all.emplace_back(val);
    }
    rec(val * 10 + 3, true, five, seven, num);
    rec(val * 10 + 5, three, true, seven, num);
    rec(val * 10 + 7, three, five, true, num);
}

int main()
{
    int N;
    std::cin >> N;
    rec(0, false, false, false, N);
    std::cout << all.size() << std::endl;
    return 0;
}
