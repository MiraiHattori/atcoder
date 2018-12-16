#include <bits/stdc++.h>


int check(const int& m, const int& N, const std::vector<int>& a)
{
    std::map<int, int> mp;
    for (int i = 1; i < N; i++) {
        if (a.at(i - 1) < a.at(i)) {
            continue;
        }
        if (m == 1) {
            return true;
        }
        int pos = a.at(i);
        while (true) {
            if (mp[pos] < m - 1) {
                mp[pos]++;
                mp.erase(mp.upper_bound(pos), mp.end());
                break;
            }
            pos--;
            if (pos == 0) {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int N;
    std::cin >> N;
    std::vector<int> as(N);
    for (int i = 0; i < N; i++) {
        std::cin >> as.at(i);
    }
    int l = 0, r = N;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m, N, as)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << r << std::endl;
    return 0;
}
