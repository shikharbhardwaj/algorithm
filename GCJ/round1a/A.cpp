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


size_t ComputeLongestCommonSuffix(const string& s0, const string& s1) {
    auto it0 =  s0.rbegin(), it1 = s1.rbegin();

    while (it0 != s0.rend() && it1 != s1.rend()) {
        if (*it0 != *it1) break;

        ++it0; ++it1;
    }

    return distance(s0.rbegin(), it0);
}

size_t ComputeLongestCommonPrefix(const string& s0, const string& s1) {
    auto it0 =  s0.begin(), it1 = s1.begin();

    while (it0 != s0.end() && it1 != s1.end()) {
        if (*it0 != *it1) break;

        ++it0; ++it1;
    }

    return distance(s0.begin(), it0);
}

vector<string> split(string s0, char delim) {
    stringstream ss(s0);

    vector<string> tokens;
    string token;

    for (auto e : s0) {
        if (e == delim) {
            tokens.push_back(token);
            token = "";
        } else {
            token.push_back(e);
        }
    }

    tokens.push_back(token);

    return tokens;
}

int main() {
    ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = std::cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = std::cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
    CASE {
        int n; std::cin >> n;

        vector<string> p, s;

        FOR(i, n) {
            string in; std::cin >> in;

            if (in[0] == '*') {
                p.push_back(in.substr(1));
            } else if(in.back() == '*') {
                s.push_back(in.substr(0, in.size() - 1));
            } else {
                auto parts = split(in, '*');

                if (parts.size() > 2) throw std::invalid_argument("Can't work with more than 1 asterisk.");

                s.emplace_back(parts[0]);
                p.emplace_back(parts[1]);
            }
        }


        bool ok = true;
        string ans;

        // std::cout << common_suffix_lengths << endl;
        // std::cout << p << endl;

        if (p.size() > 1) {
            sort(begin(p), end(p), [](const string& left, const string& right) {
                if (left.size() != right.size()) return left.size() < right.size();

                return left < right;
            });

            vector<int> common_suffix_lengths;

            transform(begin(p), end(p), back_inserter(common_suffix_lengths), [prev=p[0]](const string& cur) mutable {
                int value = ComputeLongestCommonSuffix(prev, cur);
                prev = cur;
                return value;
            });

            // std::cout << p << endl;
            // std::cout << common_suffix_lengths << endl;

            for (int i = 1; i < p.size(); ++i) {
                ok = ok && (common_suffix_lengths[i] == p[i - 1].size());
            }

            if (ok) {
                ans = p.back();
            }
        } else if (p.size() == 1) {
            ans = p.back();
        }

        if (s.size() > 1) {
            sort(begin(s), end(s), [](const string& left, const string& right) {
                if (left.size() != right.size()) return left.size() < right.size();

                return left < right;
            });

            vector<int> common_prefix_lengths;

            transform(begin(s), end(s), back_inserter(common_prefix_lengths), [prev=s[0]](const string& cur) mutable {
                int value = ComputeLongestCommonPrefix(prev, cur);
                prev = cur;
                return value;
            });

            // std::cout << s << endl;
            // std::cout << common_prefix_lengths << endl;

            for (int i = 1; i < s.size() && ok; ++i) {
                ok = ok && (common_prefix_lengths[i] == s[i - 1].size());
            }

            if (ok) {
                ans = s.back() + ans;
            }
        } else if(s.size() == 1) {
            ans = s.back() + ans;
        }

        std::cout << "Case #" << case_num << ": " << ((ok) ? ans : "*") << endl; 
    }
#ifndef ONLINE_JUDGE
    std::cin.rdbuf(cinbuf);    // restore
    std::cout.rdbuf(coutbuf); // restore
#endif	
}