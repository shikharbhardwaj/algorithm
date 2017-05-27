#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for (ll i = 0; i < n; ++i)
#define FOR1(i, n) for (ll i = 1; i <= n; ++i)
#define FORRange(i, a, b) for (ll i = a; i <= b; ++i)
#define endl '\n'
#define ll int64_t
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()

using namespace std;

template <class Number>
Number gcd(Number a, Number b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <class Number>
Number powermod(Number base, Number exponent, Number mod) {
  Number result = 1;
  while (exponent > 0) {
    if (exponent % 2 == 1) result = (result * base) % mod;
    exponent = exponent >> 1;
    base = (base * base) % mod;
  }
  return result;
}
template <class Number>
Number extendedEuclid(Number a, Number b, Number *x, Number *y) {
  Number t, d;
  if (b == 0) {
    *x = 1;
    *y = 0;
    return a;
  }
  d = extendedEuclid(b, a % b, x, y);
  t = *x;
  *x = *y;
  *y = t - (a / b) * (*y);
  return d;
}
template <class Number>
Number inversemod(Number a, Number n) {
  Number x, y;
  extendedEuclid(a, n, &x, &y);
  return (x < 0) ? (x + n) : x;
}

/* Use this for timing purposes
auto time1 = chrono::steady_clock::now();
auto time2 = chrono::steady_clock::now();
cout<<chrono::duration_cast<chrono::microseconds>(time2 - time1).count();
*/

ll bs(vector<ll> prefix, ll lo, ll hi, ll pos, ll k) {
  ll mid;
  if (lo > hi) return pos;
  if (lo <= hi && hi < pos) {
    mid = lo + (hi - lo) / 2;
    if (prefix[pos - 1] - prefix[mid - 1] + mid < k * (pos - mid))
      return bs(prefix, mid + 1, hi, pos, k);
    else if (prefix[pos - 1] - prefix[mid - 1] + mid >= k * (pos - mid)) {
      if (prefix[pos - 1] - prefix[mid - 2] + mid - 1 < k * (pos - mid + 1))
        return mid;
      else
        return bs(prefix, lo, mid - 1, pos, k);
    }
  }
  return 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  ll i;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ll t, n, q, temp, k, pos;
  cin >> t;
  while (t--) {
    vector<ll> a, prefix;
    cin >> n >> q;
    FOR(i, n) {
      cin >> temp;
      a.pb(temp);
    }
    sort(all(a));
    prefix.resize(n);
    prefix[0] = a[0];
    for (i = 1; i < n; i++) prefix[i] = prefix[i - 1] + a[i];
    while (q--) {
      cin >> k;
      // pos stores the location of the shortest snake which is larger than k
      auto pos_itr = upper_bound(all(a), k - 1);
      pos = pos_itr - a.begin();
      if (pos > n) pos = n;
      if (pos == 0 || pos == 1)
        cout << n - pos << endl;
      else if (pos == 2) {
        if (k - a[1] == 1)
          cout << n - 1 << endl;
        else
          cout << n - 2 << endl;
      } else if (pos > 2) {
        cout << n - bs(prefix, 0, pos - 1, pos, k) << endl;
      }
    }
  }
}
