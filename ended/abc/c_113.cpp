#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


struct City {
    int i;
    int p;
    int y;
};

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<City>> cities(N);
    std::vector<std::string> answers(M);
    for (int i = 0; i < M; i++) {
        int p, y;
        std::cin >> p >> y;
        City city;
        city.i = i;
        city.p = p;
        city.y = y;
        cities.at(p - 1).emplace_back(city);
    }

    for (auto& city_in_pref : cities) {
        std::sort(city_in_pref.begin(), city_in_pref.end(),
            [](auto a, auto b) { return a.y < b.y; });
        for (size_t i = 0; i < city_in_pref.size(); i++) {
            City city = city_in_pref.at(i);
            std::ostringstream os;
            int x = i + 1;
            int p = city.p;
            os << std::setfill('0') << std::setw(6) << p << std::setw(6) << x
               << std::setfill(' ');
            answers.at(city.i) = os.str();
        }
    }
    for (auto a : answers) {
        std::cout << a << std::endl;
    }

    return 0;
}
