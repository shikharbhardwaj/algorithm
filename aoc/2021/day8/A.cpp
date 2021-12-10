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
    cout << valid << endl;

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