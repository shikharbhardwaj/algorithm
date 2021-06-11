#include <bits/stdc++.h>

#define ONLINE_JUDGE

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

ull atoi(const string& str) {
    ull x = 0;

    for (auto e : str) {
        x *= 10;
        x += e - '0';
    }

    return x;
}

bool is_roaring(ull x) {
    string digits = to_string(x);

    if (digits.size() <= 1) return false;
    

    for (size_t len = 1; len <= digits.size() - 1; ++len) {
        auto first_num = atoi(digits.substr(0, len));

        auto nxt = first_num + 1;

        // Find if consecutive numbers exist.
        bool match = true;
        for (int i = len; i < digits.size() && match; ++nxt) {
            auto num_str = to_string(nxt);

            if (i + num_str.size() <= digits.size()) {
                match = match && (num_str == digits.substr(i, num_str.size()));
                i += num_str.size();
            } else {
                match = false;
            }
        }

        if (match) return match;
    }

    return false;
}

ull make_roaring(ull x) {
    string digits = to_string(x);

    ull best = 18446744073709551614u;

    for (int len = 1; len <= digits.size(); ++len) {
        auto first_num = atoi(digits.substr(0, len));

        string constructed = to_string(first_num);

        auto cur_num = first_num + 1;

        do {
            constructed += to_string(cur_num);
            cur_num++;
        } while(constructed.size() < digits.size());

        if (atoi(constructed) > x) best = min(best, atoi(constructed));
    }

    for (int len = 1; len <= digits.size() - 1; ++len) {
        auto first_num = atoi(digits.substr(0, len)) + 1;

        string constructed = to_string(first_num);

        auto cur_num = first_num + 1;

        do {
            constructed += to_string(cur_num);
            cur_num++;
        } while (constructed.size() < digits.size());
        

        if (atoi(constructed) > x) best = min(best, atoi(constructed));
    }

    // assert(is_roaring(best));

    return best;
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
    // cout << is_roaring(12) << endl;
    CASE {
        ull x; cin >> x;

        // ++x;
// 
        // while (!is_roaring(x)) {
        //     ++x;
        // }

        cout << "Case #" << case_num << ": " << make_roaring(x) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}