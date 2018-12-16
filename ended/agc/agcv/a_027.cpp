#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <numeric>
#include <vector>


using bint = boost::multiprecision::cpp_int;
//using bint = uint64_t;

struct Node {
public:
    Node() = default;
    Node(const bint& sum, const int& child) : sum(sum), child(child) {}
    bint sum = 0;
    int child = 0;
};

void printVec(const std::vector<Node>& vec)
{
    for (const auto& v : vec) {
        std::cout << "(" << v.sum << " " << v.child << "), ";
    }
    std::cout << std::endl;
}
void printNode(const Node& v)
{
    std::cout << "(" << v.sum << " " << v.child << "), ";
}


int main()
{
    int N, x;
    std::cin >> N >> x;
    std::vector<int> a;
    for (int i = 0; i < N; i++) {
        int a_;
        std::cin >> a_;
        a.emplace_back(a_);
    }

    int ans = 0;
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
    bint sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a.at(i);
    }

    if (sum < x) {
        std::cout << N - 1 << std::endl;
        return 0;
    } else if (sum == x) {
        std::cout << N << std::endl;
        return 0;
    }


    //if (x / 2 < sum) {

    std::vector<Node> new_nodes{Node(0, 0)};
    for (int i = 0; i < N; i++) {
        std::vector<Node> nodes = new_nodes;
        new_nodes.clear();
        bint rest_sum = 0;
        for (int i_ = i; i_ < N; i_++) {
            rest_sum += a.at(i_);
        }
        for (const auto& node : nodes) {
            if (node.sum + rest_sum < x) {
                if (node.child + N - i - 1 > ans and N - i - 1 >= 0) {
                    ans = node.child + N - i - 1;
                }
                continue;
            } else if (node.sum + rest_sum == x) {
                if (node.child + N - i > ans) {
                    ans = node.child + N - i;
                }
                continue;
            }
            // 選ばない
            new_nodes.emplace_back(Node(node.sum, node.child));
            // 選ぶ
            if (node.child > ans) {
                ans = node.child;
            }
            if (node.sum + a.at(i) < x and i != N - 1) {
                new_nodes.emplace_back(Node(node.sum + a.at(i), node.child + 1));
                if (node.child + 1 > ans) {
                    ans = node.child + 1;
                }
            } else if (node.sum + a.at(i) == x) {
                if (node.child + 1 > ans) {
                    ans = node.child + 1;
                }
            }
        }
        std::sort(nodes.begin(), nodes.end(), [](auto a, auto b) { return a.sum < b.sum; });
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            if (it + 1 == nodes.end()) {
                break;
            }
            if (it->sum == (it + 1)->sum) {
                if (it->child <= (it + 1)->child) {
                    it = nodes.erase(it);
                } else {
                    it = nodes.erase(it + 1) - 1;
                }
            }
        }
    }
    /*
    } else {
        std::reverse(a.begin(), a.end());
        std::vector<Node> new_nodes{Node(sum, N)};
        for (int i = 0; i < N; i++) {
            std::vector<Node> nodes = new_nodes;
            new_nodes.clear();
            for (const auto& node : nodes) {
                // 選ばない
                if (node.sum - a.at(i) > x) {
                    new_nodes.emplace_back(Node(node.sum - a.at(i), node.child - 1));
                } else if (node.sum - a.at(i) == x) {
                    if (node.child - 1 > ans) {
                        ans = node.child - 1;
                    }
                } else {
                    if (node.child > ans) {
                        ans = node.child;
                    }
                }
                new_nodes.emplace_back(Node(node.sum, node.child));
            }
            std::sort(nodes.begin(), nodes.end(), [](auto a, auto b) { return a.sum > b.sum; });
            for (auto it = nodes.begin(); it != nodes.end(); it++) {
                if (it + 1 == nodes.end()) {
                    break;
                }
                if (it->sum == (it + 1)->sum) {
                    if (it->child <= (it + 1)->child) {
                        it = nodes.erase(it);
                    } else {
                        it = nodes.erase(it + 1) - 1;
                    }
                }
            }
        }
        */
    //}
    std::cout << ans << std::endl;
    return 0;
}
