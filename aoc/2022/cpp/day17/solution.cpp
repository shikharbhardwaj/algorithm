#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
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

enum class Shape {
    MINUS = 0,
    PLUS,
    EL,
    EYE,
    SQUARE
};

using Grid = vector<string>;

map<Shape, Grid> shapes = {
    {
        Shape::MINUS,
        {"####"}
    },
    {
        Shape::PLUS,
        {".#.",
         "###",
         ".#."}
    },
    {
        Shape::EL,
        {"..#",
         "..#",
         "###"}
    },
    {
        Shape::EYE,
        {"#",
         "#",
         "#",
         "#"}
    },
    {
        Shape::SQUARE,
        {"##",
         "##"}
    }
};

using Position = pair<int, int>;

struct Game {
    int max_height = 0;
    int t = 0;
    string movements;
    Grid screen;

    Game(const string& movements_) : movements(movements_) {
        screen.assign(7, ".......");
    }

    void show() {
        for (auto row : screen) {
            cout << row << endl;
        }

        cout << endl << endl;
    }

    void _copy_shape() {
        int start_y = max_height + 3;
        int start_x = 2;
        auto shape = shapes[static_cast<Shape>(t % 5)];

        while (start_y + shape.size() >= screen.size()) {
            screen.push_back(".......");
        }

        int y = start_y;
        for (int r = shape.size(); r-->0;) {
            int x = start_x;
            for (int c = 0; c < shape[0].size(); ++c) {
                screen[y][x] = shape[r][c];
                ++x;
            }
            --y;
        }
    }

    bool _valid(int x, int y) {
        return x >= 0 && x < screen[0].size() && y >= 0 && y < screen.size();
    }

    Grid _get_next_screen(Position pos, Grid shape) {
        Grid new_screen = screen;

        int y = pos.first;
        for (int r = shape.size(); r-->0; ) {
            int x = pos.second;
            for (int c = 0; c < shape[0].size(); ++c) {
                if (shape[r][c] == '#') {
                    new_screen[y][x] = '.';
                }
                ++x;
            }
            --y;
        }

        return new_screen;
    }

    Position _move_to_pos(Position cur_pos, Position new_pos, Grid shape) {
        bool valid = true;

        Grid new_screen = _get_next_screen(cur_pos, shape);

        int y = new_pos.first;
        for (int r = shape.size(); r-->0 && valid;) {
            int x = new_pos.second;
            for (int c = 0; c < shape[0].size(); ++c) {
                if (shape[r][c] == '.') {
                    ++x;
                    continue;
                }

                if (_valid(x, y) && new_screen[y][x] != '#') {
                    new_screen[y][x] = shape[r][c];
                } else {
                    valid = false;
                    break;
                }
                ++x;
            }
            --y;
        }
    
        if (valid) {
            screen = new_screen;
            return new_pos;
        }

        return cur_pos;
    }


    Position _move_left(Position pos, Grid shape) {
        return _move_to_pos(pos, {pos.first, pos.second - 1}, shape);
    }
    Position _move_right(Position pos, Grid shape) {
        return _move_to_pos(pos, {pos.first, pos.second + 1}, shape);
    }

    Position _move_sideways(Position pos, Grid shape, bool left) {
        if (left) {
            return _move_left(pos, shape);
        } else {
            return _move_right(pos, shape);
        }
    }

    Position _move_down(Position pos, Grid shape) {
        return _move_to_pos(pos, {pos.first + 1, pos.second}, shape);
    }

    void _move() {
        Position cur_pos = {max_height + 3, 2};
        Position new_pos = cur_pos;

        auto shape = shapes[static_cast<Shape>(t % 5)];

        do {
            cur_pos = _move_sideways(new_pos, shape, movements[t % (movements.size())] == '<');
            show();
            new_pos = _move_down(cur_pos, shape);
            show();
        } while (cur_pos != new_pos);

        max_height = max(max_height, new_pos.first + (int) shape.size());
    }

    void tick() {
        _copy_shape();
        _move();
        ++t;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    string input; cin >> input;

    Game game(input);
    game.show();
    game.tick();
    game.show();

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}