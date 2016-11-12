#include <iostream>

// Scheme : +- x -> +- 1
//          +- y -> +- 2
//          +- z -> +- 3
int main() {
    std::ios_base::sync_with_stdio(false);
    int length;
    while (true) {
        std::string move;
        std::cin >> length;
        int cur_dir = 1;
        if (length == 0)
            break;
        for (int i = 1; i < length; i++) {
            std::cin >> move;
            if (move == "No")
                continue;
            int move_mult = 1;
            if (move[0] == '-')
                move_mult = -1;
            int move_dir;
            if (move[1] == 'y')
                move_dir = 2;
            else
                move_dir = 3;
            move_dir *= move_mult;
            if (abs(move_dir) == abs(cur_dir)) {
                cur_dir = -1 * cur_dir * move_mult / abs(cur_dir);
            } else {
                if (abs(cur_dir) == 1) {
                    cur_dir = move_dir * cur_dir;
                }
            }
        }
        if (cur_dir < 0) {
            std::cout << "-";
            cur_dir *= -1;
        } else {
            std::cout << "+";
        }
        switch (cur_dir) {
        case 1:
            std::cout << "x\n";
            break;
        case 2:
            std::cout << "y\n";
            break;
        case 3:
            std::cout << "z\n";
            break;
        }
    }
}
