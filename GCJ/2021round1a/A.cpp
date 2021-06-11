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

enum class PREF_MATCH {
    LESS = 0,
    MORE = 1,
    SAME = 2
};

PREF_MATCH get_match(ull a, ull b) {
    auto str_a = to_string(a), str_b = to_string(b);

    for (int i = 0; i < str_a.size() && i < str_b.size(); ++i) {
        if (str_a[i] != str_b[i]) {
            return ((str_a[i] < str_b[i]) ? PREF_MATCH::LESS : PREF_MATCH::MORE);
        }
    }

    return PREF_MATCH::SAME;
}


bool is_possible_to_increment(ull x, ull y) {
    return get_match(x + 1, y) == PREF_MATCH::SAME;
}

int len(ull x) {
    return to_string(x).size();
}

int cost(ull a, ull b) {
    return std::abs(len(a) - len(b));
}

ull pad_zeros(ull a, int n) {
    return a * pow(10, n);
}

ull try_increment_or_pad(ull prev, ull x) {
    if (is_possible_to_increment(prev, x)) {
        return prev + 1;
    } else {
        return pad_zeros(x, len(prev) - len(x) + 1);
    }
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
    CASE {
        int N; cin >> N;
        vector<ull> x(N);

        for (auto& e : x) cin >> e;

        int prev = x[0];

        int ans = 0;

        for (int i = 1; i < N; ++i) {
            if (x[i] > prev) {
                prev = x[i];
                continue;
            }

            auto cur = x[i];

            auto match = get_match(x[i], prev);

            switch (match) {
                case PREF_MATCH::SAME: x[i] = try_increment_or_pad(prev, x[i]);
                break;
                case PREF_MATCH::MORE: x[i] = pad_zeros(x[i], len(prev) - len(x[i]));
                break;
                case PREF_MATCH::LESS: x[i] = pad_zeros(x[i], len(prev) - len(x[i]) + 1);
                break;
            }

            ans += cost(cur, x[i]);
            prev = x[i];
        }

        pair<int, int> test = {1, 2};

        cout << "Case #" << case_num << ": " << ans << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}