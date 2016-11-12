#include <algorithm>
#include <iostream>
#include <iterator>

typedef struct card {
    int val = 0;
    int player = 0;
    card(int v, int p) : val(v), player(p) {}
    friend std::ostream &operator<<(std::ostream &output, const card &cd) {
        output << "Card : (" << cd.player << ", " << cd.val << ")";
        return output;
    }
} card;
int main() {
    std::ios_base::sync_with_stdio(false);
    while (true) {
        int cards[53] = {0};
        int A, B, C, X, Y;
        std::cin >> A >> B >> C >> X >> Y;
        if (A == 0)
            break;
        cards[A] = 1, cards[B] = 1, cards[C] = 1, cards[X] = 1, cards[Y] = 1;
        card hand[] = {card(A, 1), card(B, 1), card(C, 1), card(X, 2),
                       card(Y, 2)};
        std::sort(hand, hand + 5,
                  [](const card &first, const card &second) -> bool {
                      return first.val < second.val;
                  });
        std::copy(hand, hand + 5, std::ostream_iterator<card>(std::cout, "\n"));
        std::cout << cards[1];
        // for (int i = start_card; i <= 52; i++) {
        // if (cards[i] != 1) {
        // std::cout << i << "\n";
        // break;
        //}
        //}
    }
}
