#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <chrono>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for (int i = 0; i < n; ++i)
#define TEST                                                                   \
  int T;                                                                       \
  std::cin >> T;                                                               \
  while (T--)

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

// The cost functions
int cost_rep(char a, char b) { return (a == b) ? 0 : 1; }
int cost_ins(char) { return 1; }
int cost_del(char) { return 1; }

int edit_distance(const string &a, const string &b) {
  /*
          The edit distance problem

          Consider the two strings a[n] and b[m]
          We maintain n x m states, each state (i, j) represents
          the number cost of changing the prefix a[0:i] to the prefix b[0:j]

          Value at state(n, m) gives the answer to the problem.
  */
  vector<vi> state(a.size() + 1);
  for_each(state.begin(), state.end(), [&](vi &in) {
    in.resize(b.size() + 1);
  });
  for (size_t i = 0; i <= b.size(); ++i) {
    state[0][i] = i;
  }
  for (size_t i = 0; i <= a.size(); ++i) {
    state[i][0] = i;
  }
  for (size_t i = 1; i <= a.size(); ++i) {
    for (size_t j = 1; j <= b.size(); ++j) {
      if (a[i - 1] == b[j - 1]) {
        state[i][j] = state[i - 1][j - 1];
      } else {
        state[i][j] = min(min(state[i - 1][j - 1] 	+ cost_rep(a[i - 1], b[j - 1]),
                              state[i - 1][j] 		+ cost_del(a[i - 1])),
                          	  state[i][j - 1] 		+ cost_ins(b[j - 1]));
      }
    }
  }
  // Show me the state
  // for_each(state.begin(), state.end(),
  //          [](const vi &in) { cout << in << endl; });
  return state[a.size()][b.size()];
}

int main() {
  ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
  ifstream fin("in.txt");
  ofstream fout("out.txt");
  auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
  auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif
  TEST{
  	string a, b;
  	cin >> a >> b;
  	cout << edit_distance(a, b) << endl;
  }
#ifndef ONLINE_JUDGE
  cin.rdbuf(cinbuf);   // restore
  cout.rdbuf(coutbuf); // restore
#endif
}
