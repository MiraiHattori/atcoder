#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

std::pair<std::vector<std::string>, std::vector<std::string>> divide(const std::vector<std::string>& cand, const std::string& p)
{
    std::pair<std::vector<std::string>, std::vector<std::string>> result;
    for (const auto& s : cand) {
        if (s.find(p.at(0)) < s.find(p.at(1))) {
            result.first.emplace_back(s);
        } else {
            result.second.emplace_back(s);
        }
    }
    return result;
}

std::string solve5(std::string ans)
{
    std::string s = "ABCDE";
    std::vector<std::string> cand{};
    do {
        cand.emplace_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    while (true) {
        std::string preffered_choice;
        int preffered_mid = std::numeric_limits<int>::max();
        for (std::string p : {"AB", "AC", "AD", "AE", "BC", "BD", "BE", "CD", "CE", "DE"}) {
            if (std::abs(static_cast<double>(divide(cand, p).first.size()) - static_cast<double>(cand.size() / 2.0)) < preffered_mid) {
                preffered_mid = std::abs(static_cast<double>(divide(cand, p).first.size()) - static_cast<double>(cand.size() / 2.0));
                preffered_choice = p;
            }
        }
        static std::string pre = preffered_choice;
        pre = preffered_choice;
        if (ans.find(preffered_choice.at(0)) > ans.find(preffered_choice.at(1))) {
            cand = divide(cand, preffered_choice).second;
        } else {
            cand = divide(cand, preffered_choice).first;
        }
        if (cand.size() == 1) {
            break;
        }
    }
    return cand.at(0);
}


int main()
{
    std::string ans = "ABCDE";
    do {
        if (ans != solve5(ans)) {
            std::cout << "ans: " << ans << " " << solve5(ans) << std::endl;
        }
    } while (std::next_permutation(ans.begin(), ans.end()));
    return 0;
}
