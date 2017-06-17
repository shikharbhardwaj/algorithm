#define _CRT_SECURE_NO_WARNINGS

#include <emmintrin.h>
#include <mmintrin.h>
#include <string.h>
#include <xmmintrin.h>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef pair<int, int> ipair;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
#define SIZE(A) ((int)(A.size()))
#define LENGTH(A) ((int)(A.length()))
#define MP(A, B) make_pair(A, B)
const double pi = acos(-1.0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a) for (int i = 0; i < (a); ++i)
#define ALL(a) (a).begin(), (a).end()

template <class T>
T sqr(const T& x) {
  return x * x;
}

template <class T>
T lowbit(const T& x) {
  return (x ^ (x - 1)) & x;
}

template <class T>
int countbit(const T& n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}

template <class T>
void ckmin(T& a, const T& b) {
  if (b < a) a = b;
}

template <class T>
void ckmax(T& a, const T& b) {
  if (b > a) a = b;
}

int m, n;
int c[4];
// Explanation of the state
// f[x][y][z][d] --> Use x, y, z groups of mod 1, 2, 3 to get the max fresh groups
int f[128][128][128][4];

int solve(int c1, int c2, int c3, int d) {
  if (c1 + c2 + c3 == 0) return 0;
  int& ret = f[c1][c2][c3][d];

  if (ret >= 0) {
  	// We have procomputed this
  	return ret;
  }

  ret = 0;
  int base = 0;
  if (d == 0) ++base; // The next group must get fresh chocolates
  if (c1 > 0) ckmax(ret, solve(c1 - 1, c2, c3, (d + 1) % n) + base);
  if (c2 > 0) ckmax(ret, solve(c1, c2 - 1, c3, (d + 2) % n) + base);
  if (c3 > 0) ckmax(ret, solve(c1, c2, c3 - 1, (d + 3) % n) + base);
  return ret;
}
int solve() {
  memset(f, 255, sizeof(f));
  return c[0] + solve(c[1], c[2], c[3], 0);
}
int main() {
  // freopen("A.in","r",stdin);
  // freopen("A-small-attempt0.in","r",stdin);
  // freopen("A-small-attempt0.out","w",stdout);
  // freopen("A-small-attempt1.in","r",stdin);
  // freopen("A-small-attempt1.out","w",stdout);
  // freopen("A-small-attempt2.in","r",stdin);
  // freopen("A-small-attempt2.out","w",stdout);
  freopen("A-large-practice.in", "r", stdin);
  freopen("out.txt", "w", stdout);

  // std::ios_base::sync_with_stdio(false);
  int ntestcase;
  cin >> ntestcase;
  for (int case_id = 1; case_id <= ntestcase; ++case_id) {
    cin >> m >> n;
    memset(c, 0, sizeof(c));
    REP(i, m) {
      int d;
      cin >> d;
      ++c[d % n];
    }
    printf("Case #%d: %d\n", case_id, solve());
  }
  return 0;
}
