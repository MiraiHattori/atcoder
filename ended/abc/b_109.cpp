#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    bool first = true;
    std::string w;
    std::vector<std::string> ws;
    bool yes = true;
    char buf;
    for (int i = 0; i < n; i++) {
        std::cin >> w;
        if (not first) {
            if (w.at(0) != buf) {
                yes = false;
                break;
            }
        }
        first = false;
        buf = w.at(w.size() - 1);
        if (std::find(ws.begin(), ws.end(), w) != ws.end()) {
            yes = false;
            break;
        }
        ws.emplace_back(w);
    }
    std::cout << (yes ? "Yes" : "No") << std::endl;
    return 0;
}
