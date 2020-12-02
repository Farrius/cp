#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;
	set<int> st;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	if ((int) st.size() == n - 1) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
