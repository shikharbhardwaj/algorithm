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

int bits_to_int(const string& bits) {
    int b = 1, a = 0;

    for (int i = bits.size(); i --> 0; ) {
        if (bits[i] - '0') a += b;
        b *= 2;
    }

    return a;
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
    const int MAX_BIT_COUNT = 20;
    vector<int> set_count(MAX_BIT_COUNT);
    multiset<string> inputs;

    int bit_count = MAX_BIT_COUNT;

    string input;
    while (cin >> input) {
        inputs.emplace(input);
    }

    auto update_set_count = [&]() {
        fill(begin(set_count), end(set_count), 0);

        for (auto input : inputs) {
            for (int i = 0; i < input.size(); ++i) {
                set_count[i] += input[i] - '0';
            }
        }
    };

    auto gamma_candidates = inputs;

    int current_bit = 0;

    while (gamma_candidates.size() > 1) {
        int current_bit_set_count = 0;

        for (auto input : gamma_candidates) {
            current_bit_set_count += input[current_bit] - '0';
        }

        multiset<string> to_keep;
        bool keep_one = current_bit_set_count >= gamma_candidates.size() / 2.0;

        for (auto input : gamma_candidates) {
            if (input[current_bit] > '0' && keep_one) to_keep.emplace(input);
            else if (input[current_bit] == '0' && !keep_one) to_keep.emplace(input);
        }

        gamma_candidates = to_keep;
        ++current_bit;
    }


    int gamma = bits_to_int(*gamma_candidates.begin());

    auto beta_candidates = inputs;

    current_bit = 0;

    while (beta_candidates.size() > 1) {
        int current_bit_set_count = 0;

        for (auto input : beta_candidates) {
            current_bit_set_count += input[current_bit] - '0';
        }

        multiset<string> to_keep;
        bool keep_one = current_bit_set_count < beta_candidates.size() / 2.0;

        for (auto input : beta_candidates) {
            if (input[current_bit] > '0' && keep_one) to_keep.emplace(input);
            else if (input[current_bit] == '0' && !keep_one) to_keep.emplace(input);
        }

        beta_candidates = to_keep;
        ++current_bit;
    }

    int beta = bits_to_int(*beta_candidates.begin());
    cout << gamma_candidates << endl;
    cout << beta_candidates << endl;

    cout << gamma * beta << endl;

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}