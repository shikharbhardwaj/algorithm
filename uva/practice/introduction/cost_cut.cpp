#include <bits/stdc++.h>
template <typename Iter> void insertion_sort(Iter begin, Iter end) {
    for (auto it = begin + 1; it != end; it++) {
        auto val = *it;
        auto jt = it - 1;
        while (jt != begin - 1 && *jt > val) {
            *(jt + 1) = *jt;
            jt--;
        }
        *(jt + 1) = val;
    }
}
int main() {
    int T;
    std::cin >> T;
    for (int c = 1; c <= T; c++) {
        int i, j, k;
        std::cin >> i >> j >> k;
        std::vector<int> temp({i, j, k});
        // std::sort(temp.begin(), temp.end());
        insertion_sort(temp.begin(), temp.end());
        std::cout << "Case " << c << ": " << temp[1] << "\n";
    }
}
