#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> shs;
    std::vector<int> sms;
    std::vector<int> ehs;
    std::vector<int> ems;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        int sh = std::stoi(str.substr(0, 2));
        int sm = std::stoi(str.substr(2, 2));
        sm -= sm % 5;
        int eh = std::stoi(str.substr(5, 2));
        int em = std::stoi(str.substr(7, 2));

        if (em > 55) {
            eh++;
            em = 0;
        } else if (em % 5 != 0) {
            em = (em - em % 5) + 5;
        }

        shs.emplace_back(sh);
        sms.emplace_back(sm);
        ehs.emplace_back(eh);
        ems.emplace_back(em);
    }
    std::vector<bool> used(N);
    for (int i = 0; i < N; i++) {
        used.at(i) = false;
    }
    while (true) {
        bool is_all_used = true;
        for (int i = 0; i < N; i++) {
            if (not used.at(i)) {
                is_all_used = false;
            }
        }
        if (is_all_used) {
            break;
        }
        int min = std::numeric_limits<int>::max();
        int min_i = -1;
        for (int i = 0; i < N; i++) {
            if (used.at(i)) {
                continue;
            }
            if (shs.at(i) * 100 + sms.at(i) < min) {
                min = shs.at(i) * 100 + sms.at(i);
                min_i = i;
            }
        }
        used.at(min_i) = true;
        int start = shs.at(min_i) * 100 + sms.at(min_i);
        int end = ehs.at(min_i) * 100 + ems.at(min_i);
        while (true) {
            bool is_all_applicable = true;
            for (int i = 0; i < N; i++) {
                if (used.at(i)) {
                    continue;
                }
                if (shs.at(i) * 100 + sms.at(i) <= end) {
                    used.at(i) = true;
                    is_all_applicable = false;
                    if (ehs.at(i) * 100 + ems.at(i) > end) {
                        end = ehs.at(i) * 100 + ems.at(i);
                    }
                }
            }
            if (is_all_applicable) {
                break;
            }
        }
        std::cout << std::right << std::setfill('0') << std::setw(4) << start << "-" << std::setw(4) << end << std::endl;
    }
    return 0;
}
