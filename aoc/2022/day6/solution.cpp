#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
#include <deque>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
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
    string input;
    cin >> input;

    deque<char> current_window;

    const int detection_size = 14;

    for (int i = 0; i < detection_size - 1; ++i) {
        current_window.push_back(input[i]);
    }

    for (int i = detection_size - 1; i < input.size(); ++i) {
        current_window.push_back(input[i]);
    
        set<char> unique_chars(ALL(current_window));
    
        if (unique_chars.size() == detection_size) {
            cout << i + 1 << endl;
            break;
        }
        current_window.pop_front();
    }

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif
}