#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for (size_t i = 0; i < n; ++i)
#define FOR1(i, n) for (size_t i = 1; i <= n; ++i)
#define FORRange(i, a, b) for (size_t i = a; i <= b; ++i)
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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ll i, j;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll t, a, b, n, l, h[100005], cost, pos, neg, dp[100006], mincost, count,
	range, zero;
	cin >> t;
	while (t--) {
		multiset<ll> heads;
		cin >> n >> l >> a >> b;
		FOR(i, n) {
			cin >> h[i];
			heads.insert(h[i]);
		}
		range = b - (l * n);
		pos = neg = zero = 0;
		FOR(i, n) {
    // First element
			if (i == 0) {
				if (a + (i * l) > h[i]) {
					pos++;
					dp[i] = (a - h[i]);
				} else if (a + (i * l) < h[i]) {
					neg++;
					dp[i] = (h[i] - a);
				} else {
					zero++;
					dp[i] = 0;
				}
			} else {
				if (a + (i * l) > h[i]) {
					pos++;
					dp[i] = dp[i - 1] + (a - h[i] + l * i);
				} else if (a + (i * l) < h[i]) {
					neg++;
					dp[i] = dp[i - 1] - (a - h[i] + l * i);
				} else {
					zero++;
					dp[i] = dp[i - 1];
				}
			}
		}
		cost = dp[n - 1];
		mincost = cost;
		for (i = a + 1; i <= range; i++) {
			while (zero > 0) {
				zero--;
				neg++;
			}
			count = heads.count(i);
			while (count--) {
				pos--;
				zero++;
			}
			cost = cost + pos - neg;
			mincost = min(cost, mincost);
		}
		cout << mincost << endl;
	}
}