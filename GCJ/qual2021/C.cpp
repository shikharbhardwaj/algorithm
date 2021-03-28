#include <bits/stdc++.h>

// #define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define FOR1(i, n) for(int i = 1; i <= n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define CASE int cases; std::cin >> cases; FOR1(case_num, cases)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;


int reversort_cost(vector<int> ar) {
    int cost = 0;

    for (size_t i = 0; i < ar.size() - 1; i++) {
        auto min_it = min_element(begin(ar) + i, end(ar));

        cost += distance(begin(ar) + i, next(min_it));

        reverse(begin(ar) + i, next(min_it));
    }

    return cost;
}

int min_limit(int n) {
    return n - 1;
}

int max_limit(int n) {
    return (n * (n + 1) / 2) - 1;
}

map<int, map<int, vector<int>>> possibilities;

void try_inserts(int n, int k) {
    auto lower = possibilities[n - 1][k];

    for (int i = 0; i < lower.size(); ++i) {
        auto next = lower;
        next.insert(begin(next) + i, n);
        possibilities[n][reversort_cost(next)] = next;
    }

    {
        auto next = lower;
        next.push_back(n);
        possibilities[n][reversort_cost(next)] = next;
    }
}

void generate() {
    possibilities[2][1] = {1, 2};
    possibilities[2][2] = {2, 1};

    for (int n = 3; n <= 100; ++n) {
        int num_costs = max_limit(n - 1) - min_limit(n - 1) + 1;

        int target = max_limit(n) - min_limit(n);

        vector<int> idx(num_costs);
        iota(begin(idx), end(idx), min_limit(n - 1));
        random_shuffle(begin(idx), end(idx));

        for (auto k : idx) {
            while (possibilities[n].size() < target) try_inserts(n, k);
        }

        cout << "Done " << n << endl;
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
    generate();
    CASE {
        int N, C; cin >> N >> C;

        // Generate all N! permutations.
        vector<int> permutation(N);
        iota(begin(permutation), end(permutation), 1);

        auto end_permutation = permutation;
        reverse(begin(end_permutation), end(end_permutation));

        bool found = reversort_cost(permutation) == C;

        do {
            if (found) break;

            next_permutation(begin(permutation), end(permutation));

            found = reversort_cost(permutation) == C;
        } while (permutation != end_permutation);

        // bool found = possibilities[N].find(C) != possibilities[N].end();

        if (found) {
            cout << "Case #" << case_num << ": ";
            // copy(begin(possibilities[N][C]), end(possibilities[N][C]), ostream_iterator<int>(cout, " "));
            copy(begin(permutation), end(permutation), ostream_iterator<int>(cout, " "));
            cout << endl;
        } else {
            cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}
