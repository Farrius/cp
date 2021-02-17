#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int n;
int bit[MX * 2];
ll cnt[MX];

void upd (int i, int val) {
	for (; i < MX; i += i&(-i)) {
		bit[i] += val;
	}
}

int query (int i) {
	int res = 0;
	for (; i > 0; i -= i&(-i)) {
		res += bit[i];
	}
	return res;
}

int main () {
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x++;
		cnt[x] += i - query(x);
		upd(x, 1);
	}
	ll inv = 0;
	for (int i = 1; i <= n; i++) {
		cout << inv << '\n';
		inv += cnt[i];
	}
}
