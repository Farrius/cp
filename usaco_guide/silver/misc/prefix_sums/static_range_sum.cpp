#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, q;
	cin >> n >> q;
	int ar[n];
	long long pref[n + 1] = {0};
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		pref[i + 1] = pref[i] + ar[i];
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << pref[r] - pref[l] << '\n';
	}
}
