#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main () {
	int n;
	cin >> n;
	Tree<int> ts;
	int p[n];
	for (int i = 0; i < n; i++) {
		ts.insert(i);
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		int in;
		cin >> in;
		in--;

		cout << p[pos] << (i == n - 1 ? '\n' : ' ');
	}
}	
