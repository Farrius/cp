#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MX = 1e7 + 5;

int n;
ll bit[MX];

void upd (int i) {
	for (;i <= MX; i += (i&(-i))) {
		bit[i]++;
	}
}

ll query (int i) {
	ll res = 0;
	for (; i > 0; i -= (i&(-i))) {
		res += bit[i];
	}
	return res;
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		ll sol = 0;
		memset(bit, 0, sizeof(bit));
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			sol += query(ar[i]);
			upd(ar[i]);
		}
		cout << sol << '\n';
	}
}
