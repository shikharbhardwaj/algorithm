#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <cassert>
#include <deque>
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

vector<string> split(const string& str, char delim=' ') {
    istringstream ss(str);
    string token;
    vector<string> tokens;

    while (getline(ss, token, delim)) {
        if (!token.empty()) tokens.push_back(token);
    }

    return tokens;
}

enum class Operation {
    ADD = 0,
    SUB,
    MUL,
    DIV,
    SQU
};

ostream& operator<<(ostream& os, Operation op) {
    return os << (int) op;
}

Operation char_to_op(char ch) {
    switch (ch) {
        case '+': return Operation::ADD;
        case '-': return Operation::SUB;
        case '*': return Operation::MUL;
        case '/': return Operation::DIV;
    }
    throw std::logic_error("Operation not implemented.");
}

int apply_op(int op0, int op1, Operation op) {
    switch (op) {
        case Operation::ADD: return op0 + op1;
        case Operation::SUB: return op0 - op1;
        case Operation::MUL: return op0 * op1;
        case Operation::DIV: return op0 / op1;
        case Operation::SQU: return op0 * op0;
    }

    throw std::logic_error("Operation not implemented.");
}

ull apply_op(ull op0, ull op1, Operation op) {
    switch (op) {
        case Operation::ADD: return op0 + op1;
        case Operation::SUB: return op0 - op1;
        case Operation::MUL: return op0 * op1;
        case Operation::DIV: return op0 / op1;
        case Operation::SQU: return op0 * op0;
    }

    throw std::logic_error("Operation not implemented.");
}

struct Monkey {
    deque<ull> items;
    Operation op;
    ull operand;
    ull test_divisor;
    int test_true_idx, test_false_idx;

    deque<map<ull, ull>> items_by_divisor;

    int num_inspected=0;

    Monkey(deque<ull> items_, Operation op_, int operand_, int test_divisor_,
    int test_true_idx_, int test_false_idx_) : items(items_), op(op_),
    operand(operand_), test_divisor(test_divisor_),
    test_true_idx(test_true_idx_), test_false_idx(test_false_idx_) {}

    void inspect(vector<Monkey>& troop, int cur_idx) {
        deque<ull> remaining;
    
        while (!items.empty()) {
            auto level = items.front();
            items.pop_front();
            level = apply_op(level, operand, op);
            level /= 3;

            if (level % test_divisor == 0) {
                if (test_true_idx != cur_idx) troop[test_true_idx].items.push_back(level);
                else remaining.push_back(level);
            } else {
                if (test_false_idx != cur_idx) troop[test_false_idx].items.push_back(level);
                else remaining.push_back(level);
            }
            ++num_inspected;
        }

        items = remaining;
    }

    void initialize_divisors(vector<Monkey>& troop, int idx) {
        for (auto e : items) {
            map<ull, ull> item_by_divisor;
            for (auto monkey : troop) {
                item_by_divisor[monkey.test_divisor] = e % monkey.test_divisor;
            }
            items_by_divisor.emplace_back(item_by_divisor);
        }
    }

    void inspect_without_reset(vector<Monkey>& troop, int cur_idx) {
        while (!items_by_divisor.empty()) {
            auto level_by_divisor = items_by_divisor.front();
            items_by_divisor.pop_front();

            map<ull, ull> new_level_by_divisor;

            for (auto [d, v] : level_by_divisor) {
                v %= d;
                auto new_level = apply_op(v, operand % d, op) % d;
                new_level_by_divisor[d] = new_level;
            }


            if (new_level_by_divisor[test_divisor] == 0) {
                if (test_true_idx != cur_idx) troop[test_true_idx].items_by_divisor.push_back(new_level_by_divisor);
            } else {
                if (test_false_idx != cur_idx) troop[test_false_idx].items_by_divisor.push_back(new_level_by_divisor);
            }
            ++num_inspected;
        }
    }
};

ostream& operator<<(ostream& os, const Monkey& monkey) {
    os << "Monkey(num_inspected=" << monkey.num_inspected;
    os << ", items_by_divisor=" << monkey.items_by_divisor << ", items=" << monkey.items << ", op=" << monkey.op << ", operand=" << monkey.operand;
    os << ", test_divisor=" << monkey.test_divisor << ", test_true_idx=" << monkey.test_true_idx << ", test_false_idx=" << monkey.test_false_idx << ")";

    return os;
}

Monkey parse_monkey() {
    string starting_items_line;
    getline(cin, starting_items_line);
    auto start_tokens = split(starting_items_line);
    deque<ull> items;
    transform(begin(start_tokens) + 2, end(start_tokens), back_inserter(items), [](string val) {
        if (val.back() == ',') val.pop_back();
        return stoi(val);
    });

    string operation_line;
    getline(cin, operation_line);
    auto op_tokens = split(operation_line);
    Operation op;
    int operand;

    if (op_tokens[3] != "old") {
        cout << "Failed for: " << operation_line << endl;
        cout << "Tokens: " << op_tokens << endl;
    }

    assert(op_tokens[3] == "old"s);
    assert(op_tokens[4].size() == 1);

    if (op_tokens[5] != "old") {
        op = char_to_op(op_tokens[4][0]);
        operand = stoi(op_tokens[5]);
    } else {
        if (op_tokens[4] == "*") {
            op = Operation::SQU;
        } else if (op_tokens[4] == "+") {
            op = Operation::MUL;
            operand = 2;
        } else {
            throw std::logic_error("Could not map operation for line: " + operation_line);
        }
    }

    string test_divisor_line;
    getline(cin, test_divisor_line);
    auto test_divisor_tokens = split(test_divisor_line);
    int test_divisor = stoi(test_divisor_tokens.back());

    string test_true_idx_line;
    getline(cin, test_true_idx_line);
    auto test_true_idx_tokens = split(test_true_idx_line);
    int test_true_idx = stoi(test_true_idx_tokens.back());

    string test_false_idx_line;
    getline(cin, test_false_idx_line);
    auto test_false_idx_tokens = split(test_false_idx_line);
    int test_false_idx = stoi(test_false_idx_tokens.back());
    
    return Monkey(items, op, operand, test_divisor, test_true_idx, test_false_idx);
}

void solve_part1() {
    string line;
    vector<Monkey> troop;
    while (getline(cin, line)) {
        getline(cin, line);
        troop.emplace_back(parse_monkey());
    }

    int rounds=20;

    while (rounds--) {
        for (size_t i = 0; i < troop.size(); i++) {
            troop[i].inspect(troop, i);
        }
    }

    vector<int> inspect_counts;
    transform(begin(troop), end(troop), back_inserter(inspect_counts), [](const Monkey& monkey) {
        return monkey.num_inspected;
    });
    sort(begin(inspect_counts), end(inspect_counts), greater<ull>());

    cout << inspect_counts[0] * inspect_counts[1] << endl;
}

void solve_part2() {
    string line;
    vector<Monkey> troop;
    while (getline(cin, line)) {
        getline(cin, line);
        troop.emplace_back(parse_monkey());
    }

    for (int i = 0; i < troop.size(); ++i) {
        troop[i].initialize_divisors(troop, i);
    }
    int rounds=10000;

    while (rounds--) {
        for (size_t i = 0; i < troop.size(); i++) {
            troop[i].inspect_without_reset(troop, i);
        }
    }

    for (auto e: troop) {
        cout << e << endl;
    }

    vector<ull> inspect_counts;
    transform(begin(troop), end(troop), back_inserter(inspect_counts), [](const Monkey& monkey) {
        return monkey.num_inspected;
    });
    sort(begin(inspect_counts), end(inspect_counts), greater<ull>());

    cout << inspect_counts[0] * inspect_counts[1] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in2.txt");
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