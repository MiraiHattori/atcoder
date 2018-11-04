#include <cmath>
#include <iostream>
#include <limits>

int main()
{
    int Deg, Dis;
    std::cin >> Deg >> Dis;

    int persec = Dis;
    int mod = persec % 6;
    if (mod >= 3) {
        persec = persec - persec % 6 + 6;
    } else {
        persec = persec - persec % 6;
    }
    persec /= 6;

    int power = 0;
    if (0 <= persec and persec <= 2) {
        power = 0;
    } else if (3 <= persec and persec <= 15) {
        power = 1;
    } else if (16 <= persec and persec <= 33) {
        power = 2;
    } else if (34 <= persec and persec <= 54) {
        power = 3;
    } else if (55 <= persec and persec <= 79) {
        power = 4;
    } else if (80 <= persec and persec <= 107) {
        power = 5;
    } else if (108 <= persec and persec <= 138) {
        power = 6;
    } else if (139 <= persec and persec <= 171) {
        power = 7;
    } else if (172 <= persec and persec <= 207) {
        power = 8;
    } else if (208 <= persec and persec <= 244) {
        power = 9;
    } else if (245 <= persec and persec <= 284) {
        power = 10;
    } else if (285 <= persec and persec <= 326) {
        power = 11;
    } else {
        power = 12;
    }
    if (power == 0) {
        std::cout << 'C' << " " << 0 << std::endl;
        return 0;
    }

    std::string str = "";
    if (112.5 <= Deg and Deg < 337.5) {
        str = "NNE";
    } else if (337.5 <= Deg and Deg < 562.5) {
        str = "NE";
    } else if (562.5 <= Deg and Deg < 787.5) {
        str = "ENE";
    } else if (787.5 <= Deg and Deg < 1012.5) {
        str = "E";
    } else if (1012.5 <= Deg and Deg < 1237.5) {
        str = "ESE";
    } else if (1237.5 <= Deg and Deg < 1462.5) {
        str = "SE";
    } else if (1462.5 <= Deg and Deg < 1687.5) {
        str = "SSE";
    } else if (1687.5 <= Deg and Deg < 1912.5) {
        str = "S";
    } else if (1912.5 <= Deg and Deg < 2137.5) {
        str = "SSW";
    } else if (2137.5 <= Deg and Deg < 2362.5) {
        str = "SW";
    } else if (2362.5 <= Deg and Deg < 2587.5) {
        str = "WSW";
    } else if (2587.5 <= Deg and Deg < 2812.5) {
        str = "W";
    } else if (2812.5 <= Deg and Deg < 3037.5) {
        str = "WNW";
    } else if (3037.5 <= Deg and Deg < 3262.5) {
        str = "NW";
    } else if (3262.5 <= Deg and Deg < 3487.5) {
        str = "NNW";
    } else {
        str = "N";
    }

    std::cout << str << " " << power << std::endl;

    return 0;
}
