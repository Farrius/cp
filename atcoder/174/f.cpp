#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		unordered_set<int> st(ar.begin() + l - 1, ar.end() - (n - r));
		cout << (int) st.size() << '\n';
	}
}
