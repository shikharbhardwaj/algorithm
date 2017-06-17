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
using vll = std::vector<ll>;
using vull = std::vector<ull>;

using namespace std;


// Interval tree implementation : 
// http://www.geeksforgeeks.org/interval-tree/ 

// Structure to represent an interval
struct Interval
{
	int low, high;
};

// Structure to represent a node in Interval Search Tree
struct ITNode
{
    Interval *i;  // 'i' could also be a normal variable
    int max;
    ITNode *left, *right;
};

// A utility function to create a new Interval Search Tree Node
ITNode * newNode(Interval i)
{
	ITNode *temp = new ITNode;
	temp->i = new Interval(i);
	temp->max = i.high;
	temp->left = temp->right = NULL;
};

// A utility function to insert a new Interval Search Tree Node
// This is similar to BST Insert.  Here the low value of interval
// is used tomaintain BST property
ITNode *insert(ITNode *root, Interval i)
{
    // Base case: Tree is empty, new node becomes root
	if (root == NULL)
		return newNode(i);

    // Get low value of interval at root
	int l = root->i->low;

    // If root's low value is smaller, then new interval goes to
    // left subtree
	if (i.low < l)
		root->left = insert(root->left, i);

    // Else, new node goes to right subtree.
	else
		root->right = insert(root->right, i);

    // Update the max value of this ancestor if needed
	if (root->max < i.high)
		root->max = i.high;

	return root;
}

// A utility function to check if given two intervals overlap
bool doOVerlap(Interval i1, Interval i2)
{
	if (i1.low <= i2.high && i2.low <= i1.high)
		return true;
	return false;
}

// The main function that searches a given interval i in a given
// Interval Tree.
Interval *overlapSearch(ITNode *root, Interval i)
{
    // Base Case, tree is empty
	if (root == NULL) return NULL;

    // If given interval overlaps with root
	if (doOVerlap(*(root->i), i))
		return root->i;

    // If left child of root is present and max of left child is
    // greater than or equal to given interval, then i may
    // overlap with an interval is left subtree
	if (root->left != NULL && root->left->max >= i.low)
		return overlapSearch(root->left, i);

    // Else interval can only overlap with right subtree
	return overlapSearch(root->right, i);
}

void inorder(ITNode *root)
{
	if (root == NULL) return;

	inorder(root->left);

	cout << "[" << root->i->low << ", " << root->i->high << "]"
	<< " max = " << root->max << endl;

	inorder(root->right);
}

ll N, K, M;
bool first_rect(int x1, int y1, int x2, int y2) {
}

int main(){
	ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	auto cinbuf = cin.rdbuf(fin.rdbuf());    // save and redirect
	auto coutbuf = cout.rdbuf(fout.rdbuf()); // save and redirect
#endif	

	TEST{
		cin >> N >> K >> M;
		ITNode *root = nullptr;
		// The total interval is from 1 to 4*K
		ll x1, y1, x2, y2, xm, ym;
		ll beg, end;
		FOR(i, N){
			cin >> x1 >> y1 >> x2 >> y2;
			xm = min(x1, x2);
			x1 = (xm == x1) ? x1 : x2;
			x2 = (xm == x2) ? x1 : x2;
			ym = min(y1, y2);
			y1 = (ym == y1) ? y1 : y2;
			y2 = (ym == y2) ? y1 : y2;
			if(y1 == y2){
				if(!((x1 <= (N - K) / 2 && x2 <= (N - K) / 2) || 
					(x1 > (N + K) / 2 + 1 && x2 > (N + K) / 2 + 1))){
				}
			}
		}
	}

#ifndef ONLINE_JUDGE
	cin.rdbuf(cinbuf);    // restore
	cout.rdbuf(coutbuf); // restore
#endif	
}
