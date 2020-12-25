#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main () {
	int n;
	cin >> n;
	Tree<int> ist;
	int p[n];
	for (int i = 0; i < n; i++) {
		ist.insert(i);
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		int ind;
		cin >> ind;
		ind--;
		int pos = *ist.find_by_order(ind);
		ist.erase(pos);
		cout << p[pos] << (i == n - 1 ? '\n' : ' ');
	}
}	
