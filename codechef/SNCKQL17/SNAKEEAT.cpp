#include <algorithm>
#include <fstream>
#include <chrono>
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
using pii = std::pair<int, long long>;
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;

bool is_feasable(const pii& in, long long k, long long lb, const vector<pii>& prefix){
  long long id = in.first;
  if(id == 0){
    return true;
  } else{
    long long cnt = lb - id;
    if(id < k * cnt - prefix[lb - 1].second + prefix[id - 1].second){
      return true;
    } else {
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
    long long N, Q, k;
    cin >> N >> Q;
    vi lengths(N);
    FOR(i, N){
      cin >> lengths[i];
    }
    sort(lengths.begin(), lengths.end());
    vector<pii> prefix(N);
    prefix[0] = make_pair(0, lengths[0]);
    FOR(j, N - 1){
      prefix[j + 1] = make_pair(j + 1, lengths[j + 1] + prefix[j].second);
    }
    FOR(i, Q){
      cin >> k;
      long long lb = lower_bound(lengths.begin(), lengths.end(), k) - 
      lengths.begin();
      if(lb == 0){
        cout << N << endl;
      } else{
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
