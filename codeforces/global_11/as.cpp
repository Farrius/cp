#include <bits/stdc++.h>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		set<int> st;
		for (int i = 0; i < n; i++) {
			int cur;
			cin >> cur;
			st.insert(cur);
		}

		if ((int) st.size() > 1) cout << 1 << '\n';
		else cout << n << '\n';
	}
}
