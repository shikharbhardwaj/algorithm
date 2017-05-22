#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#ifndef ONLINE_JUDGE
#include <prettyprint/prettyprint.hpp>
#endif

#define FOR(i, n) for(int i = 0; i < n; ++i)
#define TEST int T; std::cin >> T; while(T--)

using ll = long long;
using ull = unsigned long long;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

bool is_feasable(const pii& in, int k, int lb, const vector<pii>& prefix){
  int id = in.first;
  if(id == 0){
    return true;
  } else{
    int cnt = lb - id;
    if(id < k * cnt - prefix[lb - 1].second + prefix[id - 1].second){
      return true;
    } else{
      return false;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
  ifstream fin("in.txt");
  ofstream fout("out.txt");
  auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
  auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif  
  TEST {
    int N, Q, k;
    cin >> N >> Q;
    vi lengths(N);
    FOR(i, N){
      cin >> lengths[i];
    }
    sort(lengths.begin(), lengths.end());
    FOR(i, Q){
      cin >> k;
      int lb = lower_bound(lengths.begin(), lengths.end(), k) - 
      lengths.begin();
      if(lb == 0){
        cout << N << endl;
      } else{
        // Find the breaking point
        vector<pair<int, int>> prefix(N);
        prefix[0] = make_pair(0, lengths[0]);
        FOR(i, N - 1){
          prefix[i + 1] = make_pair(i + 1, lengths[i + 1] + prefix[i].second);
        }
        int least_feasable = 
        lower_bound(prefix.begin(), prefix.begin() + lb, prefix[0],
          [&](const pii &left, const pii &){
            return is_feasable(left, k, lb, prefix);
          }) - prefix.begin();
        cout << N - least_feasable << endl;
      }
    }
  }
#ifndef ONLINE_JUDGE
  cin.rdbuf(cinbuf);    // restore
  cout.rdbuf(coutbuf); // restore
#endif  
}
