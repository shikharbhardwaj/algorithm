#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define FOR1(i, n) for(int i = 1; i <= n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define CASE int C; std::cin >> C; FOR1(case_num, C)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;


vector<string> split(string str, char delim) {
    istringstream ss(str);

    string token;
    vector<string> toknes;

    while (getline(ss, token, delim)) {
        if (token.empty()) continue;

        toknes.push_back(token);
    }

    return toknes;
}

vector<string> split(string str) {
    istringstream ss(str);

    string token;
    vector<string> toknes;

    while (ss >> token) {
        toknes.push_back(token);
    }

    return toknes;
}

/*

 a 
b c
 d 
e f
 g 

*/

struct SevenSegment {
    unordered_set<char> from_remain, to_remain;
    unordered_map<char, char> mapping;

    const unordered_map<string, int> segments_to_num = {
        {"cf", 1},
        {"acdeg", 2},
        {"acdfg", 3},
        {"bcdf", 4},
        {"abdfg", 5},
        {"abdefg", 6},
        {"acf", 7},
        {"abcdefg", 8},
        {"abcdfg", 9},
        {"abcefg", 0},
    };

    SevenSegment() {
        for (int i = 0; i < 7; ++i) {
            from_remain.insert('a' + i);
            to_remain.insert('a' + i);
        }
    }

    bool done() {
        return mapping.size() == 7;
    }

    void add(char from, char to) {
        mapping[from] = to;
        from_remain.erase(from);
        to_remain.erase(to);

        if (mapping.size() == 6) {
            assert(from_remain.size() == 1);
            assert(to_remain.size() == 1);

            mapping[*from_remain.begin()] = *to_remain.begin();

            from_remain.clear();
            to_remain.clear();
        }
    }

    int translate(const string& digits) {
        if (!done()) {
            throw std::runtime_error("Cannot translate with incomplete mapping.");
        }

        string mapped_digits;
        mapped_digits.reserve(digits.size());

        for (auto e : digits) {
            mapped_digits.push_back(mapping[e]);
        }

        return segments_to_num.at(mapped_digits);
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
    array<bool, 10> valid{};

    valid[2] = true;
    valid[4] = true;
    valid[3] = true;
    valid[7] = true;

    array<SevenSegment, 10> segments;

    int cnt_unique = 0;

    string line;
    while (getline(cin, line)) {
        vector<string> input_output = split(line, '|');
        auto output = input_output[1];

        auto digits = split(output);
        cout << digits << endl;

        for (auto digit : digits) {
            cnt_unique += (valid[digit.size()]);
        }
    }

    cout << cnt_unique << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}