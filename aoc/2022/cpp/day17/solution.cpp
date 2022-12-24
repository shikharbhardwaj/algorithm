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
    deque<char> movements;
    Grid screen;

    Game(const string& input) {
        screen.assign(7, ".......");
        movements = {ALL(input)};
    }

    void show() {
        for (auto row : screen) {
            cout << row << endl;
        }

        cout << endl << endl;
    }

    int _get_start_y() {
        return (screen.size() - 1 - max_height) - 3;
    }

    void _copy_shape() {
        int start_y = _get_start_y();
        auto shape = shapes[static_cast<Shape>(t % 5)];

        while (start_y - (int) shape.size() < 0) {
            screen.insert(screen.begin(), ".......");
            start_y = _get_start_y();
        }

        int start_x = 2;

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
        Position cur_pos = {_get_start_y(), 2};
        Position new_pos = cur_pos;

        auto shape = shapes[static_cast<Shape>(t % 5)];

        do {
            char current = movements.front();
            bool left = current == '<';
            movements.pop_front();
            movements.push_back(current);

            cur_pos = _move_sideways(new_pos, shape, left);
            // show();
            new_pos = _move_down(cur_pos, shape);
            // show();
        } while (cur_pos != new_pos);

        int height = (screen.size() - 1 - new_pos.first) + shape.size();
        max_height = max(max_height, height);
        // cout << "Updated max height: " << max_height << endl;
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
    ifstream fin("in2.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
    string input; cin >> input;

    Game game(input);

    int num_rocks = 2022;

    while (num_rocks--) {
        game.tick();
    }

    cout << game.max_height << endl;

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}