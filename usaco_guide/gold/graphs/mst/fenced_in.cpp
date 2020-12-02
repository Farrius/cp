#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e3 + 5;
const ll INF = 3e18;

int rows[MX], cols[MX];
int a, b, n, m;
int par[MX * MX];

int nd (int r, int c) {
	return r * m + c;
}

int get (int x) {
	return par[x] == x ? x : par[x] = get(par[x]);
}

bool unite (int x, int y) {
	x = get(x), y = get(y);
	if (x == y) return false;
	par[y] = x;
	return true;
}

int main () {
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> cols[i];
	}
	for (int j = 0; j < m; j++) {
		cin >> rows[j];
	}
	sort(cols, cols + n + 1);
	for (int i = 0; i < n; i++) {
		cols[i] = cols[i + 1] - cols[i];
	}
	cols[n] = b - cols[n];
	sort(rows, rows + m + 1);
	for (int j = 0; j < m; j++) {
		rows[j] = rows[j + 1] - rows[j];
	}
	rows[m] = a - rows[m];
	sort(cols, cols + n + 1);
	sort(rows, rows + m + 1);
	n++; m++;
	for (int i = 0; i < n * m; i++) {
		par[i] = i;
	}
	ll sol = 0;
	for (int c = 0, r = 0; c < n || r < m; ) {
		if (r == m || cols[c] < rows[r]) {
			for (int i = 0; i < m - 1; i++) {
				if (unite(nd(c, i), nd(c, i + 1))) sol += cols[c];
			}
			c++;
		} else {
			for (int j = 0; j < n - 1; j++) {
				if (unite(nd(j, r), nd(j + 1, r))) sol += rows[r];
			}
			r++;
		}
	}
	cout << sol << '\n';
}
