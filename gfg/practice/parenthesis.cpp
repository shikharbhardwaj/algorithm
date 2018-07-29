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

bool match(char open, char close) {
	if(open == '(')
		return close == ')';
	if(open == '{')
		return close == '}';
	if(open == '[')
		return close == ']';
	return false;
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
		string str;
		cin >> str;
		bool balanced = true;
		vector<char> stack;
		for(size_t i = 0; balanced && i < str.size(); ++i) {
			switch(str[i]) {
				case '(':
				stack.push_back(str[i]);
				break;
				case '[':
				stack.push_back(str[i]);
				break;
				case '{':
				stack.push_back(str[i]);
				break;
				default:
				auto last = stack.back();
				stack.pop_back();
				if(!match(last, str[i]))
					balanced = false;
			}
		}
		cout << ((balanced) ? "balanced" : "not balanced") << endl;
	}
#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
