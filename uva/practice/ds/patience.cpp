#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using LL = long long;
std::vector<std::vector<std::string>> decks;
bool move_possible() {
    for (size_t i = 1; i < decks.size(); i++) {
        if (decks[i].back() == decks[i - 1].back())
            return true;
        if (i > 1 && decks[i].back() == decks[i - 2].back())
            return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    int end = 0;
    while (!end) {
        decks.clear();
        std::string temp;
        for (int i = 0; i < 52; i++) {
            std::cin >> temp;
            if (temp == "#") {
                end = 1;
                break;
            }
            decks.push_back({temp});
        }
    }
}
