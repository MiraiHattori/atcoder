#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

char getChar(int i)
{
    char a = static_cast<char>(i + 'A');
    return a;
}

std::vector<char> cs;

bool isFirstSmaller(int i1, int i2)
{
    std::cout << "? " << cs.at(i1) << " " << cs.at(i2) << std::endl;
    char c;
    std::cin >> c;
    switch (c) {
    case '>':
        return false;
        break;
    case '<':
        return true;
        break;
    default:
        std::cerr << "error " << c << std::endl;
        break;
    }
    return false;
}

void process(int i1, int i2)
{
    if (not isFirstSmaller(i1, i2)) {
        std::swap(cs.at(i1), cs.at(i2));
    }
}

// 引数はindexたち
// 引数はcopy
void merge(std::vector<int> l, std::vector<int> r)
{
    int start = l.at(0);
    int end = l.at(0) + l.size() + r.size() - 1;
    std::vector<char> result;
    while (l.size() > 0 and r.size() > 0) {
        if (isFirstSmaller(l.at(0), r.at(0))) {
            result.emplace_back(cs.at(l.at(0)));
            l.erase(l.begin());
        } else {
            result.emplace_back(cs.at(r.at(0)));
            r.erase(r.begin());
        }
    }
    if (l.size() > 0) {
        for (const auto& l_e : l) {
            result.emplace_back(cs.at(l_e));
        }
    } else if (r.size() > 0) {
        for (const auto& r_e : r) {
            result.emplace_back(cs.at(r_e));
        }
    }
    for (int i = start; i <= end; i++) {
        cs.at(i) = result.at(i - start);
    }
}

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

void solve5()
{
    std::string s = "ABCDE";
    std::vector<std::string> cand{};
    do {
        cand.emplace_back(s);
    } while (std::next_permutation(s.begin(), s.end()));

    while (true) {
        std::string preffered_choice;
        double preffered_mid = std::numeric_limits<double>::max();
        for (std::string p : {"AB", "AC", "AD", "AE", "BC", "BD", "BE", "CD", "CE", "DE"}) {
            if (std::abs(static_cast<double>(divide(cand, p).first.size()) - static_cast<double>(cand.size() / 2.0)) < preffered_mid) {
                preffered_mid = std::abs(static_cast<double>(divide(cand, p).first.size()) - static_cast<double>(cand.size() / 2.0));
                preffered_choice = p;
            }
        }
        std::cout << "? " << preffered_choice.at(0) << " " << preffered_choice.at(1) << std::endl;
        char c;
        std::cin >> c;
        switch (c) {
        case '>':
            cand = divide(cand, preffered_choice).second;
            break;
        case '<':
            cand = divide(cand, preffered_choice).first;
            break;
        default:
            std::cerr << "error " << c << std::endl;
            break;
        }
        if (cand.size() == 1) {
            break;
        }
    }
    cs = std::vector<char>({cand.at(0).at(0), cand.at(0).at(1), cand.at(0).at(2), cand.at(0).at(3), cand.at(0).at(4)});
}

int main()
{
    int N, Q;
    std::cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        cs.emplace_back(getChar(i));
    }
    if (N == 5) {
        solve5();
    } else if (N == 26) {
        // {{{ 1段目
        process(0, 1);
        process(2, 3);
        process(4, 5);
        process(6, 7);
        process(8, 9);
        process(10, 11);
        process(12, 13);
        process(14, 15);
        process(16, 17);
        process(18, 19);
        process(20, 21);
        process(22, 23);
        process(24, 25);
        // }}}
        // {{{ 2段目
        merge({0, 1}, {2, 3});
        merge({4, 5}, {6, 7});
        merge({8, 9}, {10, 11});
        merge({12, 13}, {14, 15});
        merge({16, 17}, {18, 19});
        merge({20, 21}, {22, 23});
        // }}}
        // {{{ 3段目
        merge({0, 1, 2, 3}, {4, 5, 6, 7});
        merge({8, 9, 10, 11}, {12, 13, 14, 15});
        merge({20, 21, 22, 23}, {24, 25});
        // }}}
        // {{{ 4段目
        merge({0, 1, 2, 3, 4, 5, 6, 7}, {8, 9, 10, 11, 12, 13, 14, 15});
        merge({16, 17, 18, 19}, {20, 21, 22, 23, 24, 25});
        // }}}
        // {{{ 5段目
        merge({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, {16, 17, 18, 19, 20, 21, 22, 23, 24, 25});
        // }}}
    }
    std::cout << "! ";
    for (int i = 0; i < N; i++) {
        std::cout << cs.at(i);
    }
    std::cout << std::endl;
    return 0;
}
