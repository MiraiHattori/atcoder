#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::vector<int> as{};
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        as.emplace_back(a);
    }
    return 0;
}
