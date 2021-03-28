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

int solve(const vector<int>& pai, const vector<int>& pbi) {
    if (pai.empty() || pbi.empty()) return 0;

    auto count_less_than_or_equal = [](const vector<int> &ar, int val) {
        auto uit = upper_bound(begin(ar), end(ar), val);

        return distance(begin(ar), uit);
    };

    auto count_in_range = [](const vector<int>& ar, int lower, int upper) {
        auto uit = upper_bound(begin(ar), end(ar), upper);
        auto lit = lower_bound(begin(ar), end(ar), lower);

        return distance(lit, uit);
    };

    // For all special values, consider them to be the end of a consecutive chain.
    // Precompute correct mathces for suffixes.
    vector<int> suf_matches(pbi.size());

    size_t j = pai.size();
    for (size_t i = pbi.size(); i-- > 0;)
    {
        suf_matches[i] = ((i + 1 < pbi.size()) ? suf_matches[i + 1] : 0);

        while (j > 0 && pai[j - 1] > pbi[i])
            --j;

        if (j > 0 && pai[j - 1] == pbi[i])
        {
            suf_matches[i]++;
            --j;
        }
    }

    vector<int> pref_chain_length(pbi.size(), 1);

    for (size_t i = 1; i < pref_chain_length.size(); ++i) {
        if (pbi[i - 1] + 1 == pbi[i])
            pref_chain_length[i] = pref_chain_length[i - 1] + 1;
    }

    int best = suf_matches[0];

    for (size_t i = 0; i < pbi.size(); ++i) {
        size_t possible_chain = count_less_than_or_equal(pai, pbi[i]);

        // This chain covers number of special positions in (pbi[i] - p + 1, pbi[i])
        possible_chain = min(possible_chain, (size_t) count_in_range(pbi, pbi[i] - possible_chain + 1, pbi[i]));

        int ans = possible_chain + ((i + 1 < pbi.size()) ? suf_matches[i + 1] : 0);

        best = max(best, ans);
    }

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
    TEST {
        int n; cin >> n;
        int m; cin >> m;

        vector<int> pai, pbi;
        vector<int> nai, nbi;

        // Solve for +ve and negative separately.

        FOR (i, n) {
            int x; cin >> x;

            if (x > 0) pai.push_back(x);
            else nai.push_back(-x);
        }

        FOR (i, m) {
            int x; cin >> x;

            if (x > 0) pbi.push_back(x);
            else nbi.push_back(-x);
        }

        sort(begin(pai), end(pai));
        sort(begin(pbi), end(pbi));

        sort(begin(nai), end(nai));
        sort(begin(nbi), end(nbi));

        cout << solve(pai, pbi) + solve(nai, nbi) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}