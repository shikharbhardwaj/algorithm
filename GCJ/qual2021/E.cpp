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

double mean(const vector<int>& xs) {
    return accumulate(begin(xs), end(xs), 0) / (double) xs.size();
}

double std_dev(const vector<int>& xs) {

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
        int P; cin >> P;

        int NUM_QUESTIONS = 10000, NUM_PLAYERS = 100;
        vector<vector<bool>> answer_matrix(NUM_PLAYERS, vector<bool>(NUM_QUESTIONS));

        vector<int> question_difficulties(NUM_QUESTIONS);

        FOR(i, NUM_PLAYERS) {
            string str; cin >> str;

            FOR (j, NUM_QUESTIONS) {
                answer_matrix[i][j] = str[j] - '0';
                question_difficulties[j] += 1;
            }
        }

        // Find the player with the highest std dev in question difficulties.
        FOR(i, NUM_PLAYERS) {

        }
    }
#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}