#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, q;
	cin >> n >> q;
	vector<int> pref(n + 1);

	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		pref[i + 1] = pref[i] ^ cur;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (pref[r] ^ pref[l - 1]) << '\n';
	}
}
