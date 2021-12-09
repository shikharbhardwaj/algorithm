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

vector<string> split(const string& str, char delim) {
    istringstream ss(str);

    string token;
    vector<string> tokens;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }

    return tokens;
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
    string line; cin >> line;
    auto numbers = split(line, ',');

    array<ull, 9> counts{};

    for (auto e : numbers) {
        counts[stoi(e)]++;
    }

    const int final_day = 256;
    int day = 0;

    auto next = [&]() {
        decltype(counts) next_counts{};

        next_counts[6] = counts[0] + counts[7];
        next_counts[7] = counts[8];
        next_counts[8] = counts[0];

        for (int i = 1; i <= 6; ++i) {
            next_counts[i - 1] = counts[i];
        }

        counts = next_counts;

        // cout << counts << endl;
    };

    while (day < final_day) {
        next();
        ++day;
    }

    cout << accumulate(begin(counts), end(counts), 0ull) << endl;
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}