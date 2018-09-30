#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;
    std::vector<int> nums({A, B, C});
    std::sort(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.end());
    std::cout << nums.at(0) * 10 + nums.at(1) + nums.at(2) << std::endl;
    return 0;
}
