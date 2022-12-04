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

vector<string> split(string input, char delim = ' ') {
    istringstream ss(input);

    vector<string> tokens;
    string token;

    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
}

bool intersect(const pii& foo, const pii& bar) {
    return (max(foo.first, bar.first) <= min(foo.second, bar.second));
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
    string line;
    int count = 0, total = 0;
    while (cin >> line) {
        auto elves = split(line, ',');
        auto first_elf = split(elves[0], '-');
        auto second_elf = split(elves[1], '-');

        auto first_elf_range = make_pair(stoi(first_elf[0]), stoi(first_elf[1]));
        auto second_elf_range = make_pair(stoi(second_elf[0]), stoi(second_elf[1]));


        vector<pii> ranges = {first_elf_range, second_elf_range};
        sort(ALL(ranges), [](const pii& left, const pii& right) {
            int left_cnt = left.second - left.first;
            int right_cnt = right.second - right.first;

            return left_cnt > right_cnt;
        });
        cout << ranges << endl;

        // if (ranges[1].first >= ranges[0].first && ranges[1].second <= ranges[0].second) {
        //     count++;
        // }
        if (intersect(ranges[0], ranges[1])) {
            count++;
        }
        ++total;
    }

    cout << count << endl;
    cout << total << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}