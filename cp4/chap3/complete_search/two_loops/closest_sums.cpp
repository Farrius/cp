#include <bits/stdc++.h>

using namespace std;

int main () {
	int t = 1;
	int n;
	while (cin >> n) {
		if (n == 0) break;
		cout << "Case " << t << ":" << '\n';
		int ar[n];
		set<int> st;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				st.insert(ar[i] + ar[j]);
			}
		}
		int q;
		cin >> q;
		while (q--) {
			int x;
			cin >> x;
			cout << "Closest sum to " << x << " is ";
			auto hi = st.lower_bound(x);
			auto lo = hi;
			if (lo != st.begin()) lo--;
			if (abs(x - *lo) < abs(x - *hi)) {
				cout << *lo << '.' << 	'\n';
			} else {
				cout << *hi << '.' << '\n';
			}
		}
		t++;
	}
}
