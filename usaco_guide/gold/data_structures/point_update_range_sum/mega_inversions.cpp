#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MX = 2e5 + 5;

ll bit2[MX], bit1[MX];
int n;

void upd (int i, int val, ll ar[]) {
	for (; i <= n; i += i&(-i)) {
		ar[i] += val;
	}
}

ll query (int i, ll ar[]) {
	ll res = 0;
	for (; i; i -= i&(-i)) {
		res += ar[i];
	}
	return res;
}

int main () {
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	ll sol = 0;
	for (int i = n - 1; i >= 0; i--) {
		sol += query(ar[i] - 1, bit2);
		ll uno = query(ar[i] - 1, bit1);
		upd(ar[i], 1, bit1);
		upd(ar[i], uno, bit2);
	}
	cout << sol << '\n';
}
