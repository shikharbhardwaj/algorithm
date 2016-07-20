// Solution to the rod cutting problem for maximizing the profit
//
#include <algorithm>
#include <iostream>
#include <vector>
using ll = long long;
ll optimal_revenue(ll n, const std::vector<ll> &prices,
                   std::vector<ll> &states) {
    ll profit = states[n];
    if (n == 0) {
        return 0;
    } else if (profit == -1) {
        for (ll i = 1; i <= n; i++) {
            profit = std::max(
                profit, prices[i] + optimal_revenue(n - i, prices, states));
        }
        states[n] = profit;
    }
    return profit;
}
int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> states(n + 1, -1);
    std::vector<ll> prices(n + 1);
    prices[0] = 0;
    for (ll i = 0; i < n; i++) {
        std::cin >> prices[i + 1];
    }
    std::cout << "The optimal revenue : "
              << optimal_revenue(n - 1, prices, states) << std::endl;
}
