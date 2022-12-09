#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <sstream>

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;

using namespace std;


struct Position {
    int x, y;

    bool operator<(const Position& other) const {
        if (x != other.x) {
            return x < other.x;
        }
        return y < other.y;
    }

    Position operator +(const Position& other) const {
        return {x + other.x, y + other.y};
    }

    bool operator== (const Position& other) const {
        return x == other.x && y == other.y;
    }
};

enum class Direction {
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    UP_RIGHT,
    UP_LEFT,
    DOWN_RIGHT,
    DOWN_LEFT,
};

bool is_diagonal(Direction direction) {
    switch (direction) {
        case Direction::UP:
        case Direction::DOWN:
        case Direction::RIGHT:
        case Direction::LEFT: return false;
        default: return true;
    }
}

Direction movement_to_direction(const Position& from, const Position& to) {
    if (from == to) {
        throw std::logic_error("Cannot map movement to diagonal direction.");
    }
    int dx = from.x - to.x;
    int dy = from.y - to.y;

    if (abs(dx) < 1 || abs(dy) < 1) {
        if (dx == 0) {
            return (dy > 0) ? Direction::UP : Direction::DOWN;
        } else {
            return (dx > 0) ? Direction::RIGHT : Direction::LEFT;
        }
    }

    if (dx > 0) {
        if (dy > 0) {
            return Direction::UP_RIGHT;
        } else {
            return Direction::DOWN_RIGHT;
        }
    } else {
        if (dy > 0) {
            return Direction::UP_LEFT;
        } else {
            return Direction::DOWN_LEFT;
        }
    }
}

Position direction_to_vector(Direction dir) {
    switch (dir) {
        case Direction::UP: return {0, 1}; break;
        case Direction::DOWN: return {0, -1}; break;
        case Direction::RIGHT: return {1, 0}; break;
        case Direction::LEFT: return {-1, 0}; break;
        case Direction::UP_RIGHT: return {1, 1}; break;
        case Direction::UP_LEFT: return {-1, 1}; break;
        case Direction::DOWN_RIGHT: return {1, -1}; break;
        case Direction::DOWN_LEFT: return {-1, -1}; break;
    }

    return {0, 0};
}

ostream& operator<<(ostream& os, const Position& pos) {
    return os << "(" << pos.x << ", " << pos.y << ")";
}

bool manhattan(const Position& pos0, const Position& pos1) {
    return abs(pos1.x - pos0.x) > 1 || abs(pos1.y - pos0.y) > 1;
}

struct Rope {
    Position head, tail;

    set<Position> unique_tail_positions;

    Rope() {
        head = {0, 0};
        tail = {0, 0};
        unique_tail_positions.insert(tail);
    }

    void move_head_right() {
        auto prev_head = head;
        head.x += 1;
        if (manhattan(head, tail)) {
            tail = prev_head;
        }
        unique_tail_positions.insert(tail);
    }

    void move_head_left() {
        auto prev_head = head;
        head.x -= 1;
        if (manhattan(head, tail)) {
            tail = prev_head;
        }
        unique_tail_positions.insert(tail);
    }

    void move_head_up() {
        auto prev_head = head;
        head.y += 1;
        if (manhattan(head, tail)) {
            tail = prev_head;
        }
        unique_tail_positions.insert(tail);
    }

    void move_head_down() {
        auto prev_head = head;
        head.y -= 1;
        if (manhattan(head, tail)) {
            tail = prev_head;
        }
        unique_tail_positions.insert(tail);
    }
};

struct BiggerRope {
    vector<Position> rope;
    set<Position> unique_tail_positions;

    BiggerRope(int length) {
        rope.resize(length);
    }

    void move_head_right() {
        auto prev_head = rope[0];
        rope[0].x += 1;
        move_tail(prev_head);
        unique_tail_positions.insert(rope.back());
    }

    void move_head_left() {
        auto prev_head = rope[0];
        rope[0].x -= 1;
        move_tail(prev_head);
        unique_tail_positions.insert(rope.back());
    }

    void move_head_up() {
        auto prev_head = rope[0];
        rope[0].y += 1;
        move_tail(prev_head);
        unique_tail_positions.insert(rope.back());
    }

    void move_head_down() {
        auto prev_head = rope[0];
        rope[0].y -= 1;
        move_tail(prev_head);
        unique_tail_positions.insert(rope.back());
    }

    void move_tail(Position prev_head) {
        if (!manhattan(rope[0], rope[1])) {
            return;
        }
        rope[1] = prev_head;

        for (int i = 2; i < rope.size(); ++i) {
            if (!manhattan(rope[i - 1], rope[i])) {
                break;
            }

            auto direction = movement_to_direction(rope[i - 1], rope[i]);
            rope[i] = rope[i] + direction_to_vector(direction);
        }
    }

};

ostream& operator<<(ostream& os, const BiggerRope& rope) {
    for (auto pos : rope.rope) {
        os << pos << " ";
    }

    return os;
}

vector<string> split(const string& input, char delim=' ') {
    istringstream ss(input);

    string token;
    vector<string> tokens;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

void solve_part1() {
    string line;

    Rope rope;

    while (getline(cin, line)) {
        auto tokens = split(line);
        int steps = stoi(tokens[1]);
        switch (line[0]) {
            case 'L': while(steps--) rope.move_head_left(); break;
            case 'U': while(steps--) rope.move_head_up(); break;
            case 'R': while(steps--) rope.move_head_right(); break;
            case 'D': while(steps--) rope.move_head_down(); break;
        }
    }

    cout << rope.unique_tail_positions.size() << endl;
}

void solve_part2() {
    string line;

    BiggerRope rope(10);

    while (getline(cin, line)) {
        auto tokens = split(line);
        int steps = stoi(tokens[1]);
        switch (line[0]) {
            case 'L': while(steps--) {
                rope.move_head_left();
                // cout << rope << endl;
            }
            break;
            case 'U':
            while (steps--)
            {
                rope.move_head_up();
                // cout << rope << endl;
            }
            break;
            case 'R':
            while (steps--)
            {
                rope.move_head_right();
                // cout << rope << endl;
            }
            break;
            case 'D':
            while (steps--)
            {
                rope.move_head_down();
                // cout << rope << endl;
            }
            break;
        }
        // cout << endl;
    }

    cout << rope.unique_tail_positions.size() << endl;

    // for (auto pos : rope.unique_tail_positions) {
    //     cout << pos << endl;
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    // solve_part1();
    solve_part2();
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}