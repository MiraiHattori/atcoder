#include <iostream>

int main()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2;
    int x2_x1 = x2 - x1;
    int y2_y1 = y2 - y1;
    x3 = x2 - y2_y1;
    y3 = y2 + x2_x1;
    x4 = x1 - y2_y1;
    y4 = y1 + x2_x1;
    std::cout << x3 << " " << y3 << " " << x4 << " " << y4 << std::endl;
    return 0;
}
