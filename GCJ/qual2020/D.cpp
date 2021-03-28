#include <bits/stdc++.h>

#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)
#define CASE int C; std::cin >> C; FOR(case_num, C)
#define ALL(v) v.begin(), v.end()
using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;

enum class Action {
    NONE = 0,
    FLIP = 1,
    REVERSE = 2,
    FLIP_REVERSE = 3
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
    auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	
    //  0001101111
    // If all are CP -> Only reversal can happen.
    // If all are EP -> Only flips can happen.
    int T, B; std::cin >> T >> B;

    while (T--) {
        vi bits(B);

        vector<int> CP, EP;

        int queries = 0;

        auto cmpl = [&](int i) {
            return B - i - 1;
        };

        auto query = [&](int i) {
            cout << i + 1 << endl;
            int x; cin >> x;
            ++queries;

            return x;
        };

        auto apply = [&](Action action) {
            if ((int) action & (int) Action::FLIP) {
                // cerr << "Flip" << endl;
                for_each(begin(bits), end(bits), [](int& x) {
                    x = (x) ? 0 : 1;
                });
            }

            if ((int) action & (int) Action::REVERSE) {
                // cerr << "Reverse" << endl;
                reverse(begin(bits), end(bits));
            }
        };

        int seen = 0;

        /*
        00 -> FLIP
        01 -> FLIP + REVERSE
        10 -> REVERSE
        11 -> NA
        */

       auto print_status = [&]() {
            // cerr << "Bits: ";
            // copy(begin(bits), end(bits), ostream_iterator<int>(cerr, ""));
            // cerr << endl;
       };

       auto detect_changes = [&]() {
           if (queries > 0 && queries % 10 == 0)
           {
               // cerr << "Changes" << endl;
               bool CP_same = false, EP_same = false;

               if (!CP.empty())
               {
                   int candidate = CP.front();

                   int prev_value = bits[candidate];

                   int cur_value = query(candidate);

                   if (prev_value == cur_value)
                       CP_same = true;
               }

               if (!EP.empty())
               {
                   int candidate = EP.front();

                   int prev_value = bits[candidate];

                   int cur_value = query(candidate);

                   if (prev_value == cur_value)
                       EP_same = true;
               }

               Action action = Action::NONE;
               int mask = EP_same * (1 << 1) + CP_same * (1 << 0);

               // cerr << "Computed mask: " << mask << "(" << CP_same << ", " << EP_same << ")"<< endl;

               switch (mask)
               {
               case 0:
                   action = Action::FLIP;
                   break;
               case 1:
                   action = Action::FLIP_REVERSE;
                   break;
               case 2:
                   action = Action::REVERSE;
                   break;
               }
               apply(action);
           }
       };

       while (seen < B / 2)
       {
           if (queries > 0 && (10 + (queries - 1)) % 10 >= 8) {
               if (queries % 10 == 9) query(0);
               detect_changes();
           }

           bits[seen] = query(seen);
           bits[cmpl(seen)] = query(cmpl(seen));

           if (bits[seen] == bits[cmpl(seen)])
               EP.push_back(seen);
           else
               CP.push_back(seen);

           ++seen;
           // cerr << "Seen: " << seen << endl;
           print_status();
        }

        if (queries > 0 && queries % 10 == 0) {
            detect_changes();
        }


        for (auto e : bits) std::cout << e;
        std::cout << endl;
        
        string resp; std::cin >> resp;

        // cerr << "Received response: " << resp << endl;

        if (resp == "N") exit(1);
    }

#ifndef ONLINE_JUDGE
    cin.rdbuf(cinbuf);    // restore
    cout.rdbuf(coutbuf); // restore
#endif	
}