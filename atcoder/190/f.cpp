#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 3e5 + 5;
int n;
ll ar[MX], bit[MX * 2];

void upd (int i, int val) {
	for (; i <= n; i += i&(-i)) {
		bit[i] += val; 
	}
}

ll query (int i) {
	ll res = 0;
	for (; i > 0; i -= i&(-i)) {
		res += bit[i];
	}
	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]++;
	}
	ll inv = 0;
	
	for (int i = n - 1; i >= 0; i--) {
		inv += query(ar[i] - 1);
		upd(ar[i], 1);
	}
	cout << inv << '\n';
	for (int i = 0; i < n - 1; i++) {
		inv -= query(ar[i] - 1);
		inv += query(n) - query(ar[i]);
		cout << inv << '\n';
	}
}
