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
        int N, K; cin >> N >> K;

        vi nums(N);

        for (auto& e : nums) cin >> e;

        sort(ALL(nums));

        nums.resize(unique(ALL(nums)) - begin(nums));

        // Find consecutive gaps and pick the two best ones.
        priority_queue<int, vector<int>, greater<int>> best;

        int best2 = 0;

        if (nums[0] != 1) best.push(nums[0] - 1);
        if (nums.back() != K) best.push(K - nums.back());

        for (int i = 1; i < nums.size(); ++i) {
            auto dx = nums[i] - nums[i - 1] - 1;
            best.push((dx + 1) / 2);

            if (best.size() > 2) best.pop();

            best2 = max(best2, dx);
        }

        int spots = 0;

        while (!best.empty()) {
            spots += best.top();
            best.pop();
        }

        spots = max(spots, best2);

        cout << "Case #" << case_num << ": " << fixed << setprecision(9) << ((spots) / (double) K) << endl;
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif     
}