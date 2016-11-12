#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    int S, Q;
    while (true) {
        std::cin >> S >> Q;
        if (S == 0) {
            break;
        }
        std::vector<int> r_bud(S + 1);
        std::vector<int> l_bud(S + 1);
        int i = -1, L, R;
        std::generate(l_bud.begin(), l_bud.end(), [&i]() { return i++; });
        i = 0;
        std::generate(r_bud.begin(), r_bud.end(), [&i]() { return ++i; });
        // std::copy(l_bud.begin(), l_bud.end(),
        // std::ostream_iterator<int>(std::cout, " "));
        // std::cout << "\n";
        // std::copy(r_bud.begin(), r_bud.end(),
        // std::ostream_iterator<int>(std::cout, " "));
        for (i = 0; i < Q; i++) {
            std::cin >> L >> R;
            if (l_bud[L] == 0)
                std::cout << "* ";
            else
                std::cout << l_bud[L] << " ";
            if (r_bud[R] == S + 1)
                std::cout << "*";
            else
                std::cout << r_bud[R];
            r_bud[l_bud[L]] = r_bud[R];
            l_bud[r_bud[R]] = l_bud[L];
            std::cout << "\n";
        }
        std::cout << "-\n";
    }
}
