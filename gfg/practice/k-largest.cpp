#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <map>
#include <set>
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

int heap[101], size = 0;

void siftup(int i);
void siftdown(int i);

void insert(int in) {
	heap[size] = in;
	++size;
	siftup(size - 1);
}


int pop() {
	int ret = heap[0];
	swap(heap[0], heap[size - 1]);
	--size;
	siftdown(0);
	return ret;
}

void siftup(int i) {
	if(i == 0) return;
	if(heap[i / 2] < heap[i]) {
		swap(heap[i / 2], heap[i]);
		siftup(i / 2);
	}
}

void siftdown(int i) {
	if(2 * i >= size) return;
	int cur = i;
	if(heap[cur] < heap[2 * i]) {
		cur = 2 * i;
	}
	if(2 * i + 1 < size && heap[cur] < heap[2 * i + 1]) {
		cur = 2 * i + 1;
	}
	if(i != cur) {
		swap(heap[i], heap[cur]);
		siftdown(cur);
	}
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
	TEST {
		size = 0;
		int N, K, x;
		cin >> N >> K;

		FOR(i, N) {
			cin >> x;
			insert(x);
		}
		FOR(i, K) {
			cout << pop() << " ";
		}
		cout << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
