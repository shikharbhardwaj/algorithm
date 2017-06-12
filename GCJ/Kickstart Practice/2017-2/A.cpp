#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <vector>
#include <cstring>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define TEST     \
int T;         \
std::cin >> T; \
while (T--)

  using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

int N, P, temp;
int residue[4];
int dp[128][128][128][4];  // Max Possible states : (N / P)^P * P

int compute(int c1, int c2, int c3, int d) {
  if (c1 + c2 + c3 == 0) return 0;  // Nothing to place
  int &ret = dp[c1][c2][c3][d];
  if (ret >= 0) {
    return ret;
  }
  ret = 0;
  int base = 0;

  if (d == 0) ++base;

  if (c1 > 0) ret = max(ret, compute(c1 - 1, c2, c3, (d + 1) % P) + base); 
  if (c2 > 0) ret = max(ret, compute(c1, c2 - 1, c3, (d + 2) % P) + base); 
  if (c3 > 0) ret = max(ret, compute(c1, c2, c3 - 1, (d + 3) % P) + base);

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
  ifstream fin("A-large-practice.in");
  ofstream fout("out.txt");
  auto cinbuf = cin.rdbuf(fin.rdbuf());     // save and redirect
  auto coutbuf = cout.rdbuf(fout.rdbuf());  // save and redirect
#endif
  int T;
  cin >> T;
  FOR(t, T) {
    cin >> N >> P;
    memset(residue, 0, sizeof(residue));
    FOR(i, N) {
      cin >> temp;
      residue[temp % P]++;
    }
    memset(dp, 255, sizeof(dp));
    cout << "Case #" << t + 1 << ": " << residue[0] + compute(residue[1], residue[2], residue[3], 0) << endl;
    
  }
#ifndef ONLINE_JUDGE
  cin.rdbuf(cinbuf);    // restore
  cout.rdbuf(coutbuf);  // restore
#endif
}
