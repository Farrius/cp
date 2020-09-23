#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	int h[n + 1], g[n + 1], j[n + 1];

	for (int i = 0; i < n; i++) {
		h[i + 1] = h[i];
		g[i + 1] = g[i];
		j[i + 1] = j[i];
		int id;
		cin >> id;

		if (id == 1) h[i + 1]++;
		else if (id == 2) g[i + 1]++;
		else j[i + 1]++;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << h[r] - h[l - 1] << ' ' << g[r] - g[l - 1] << ' ' << j[r] - j[l - 1] << '\n';
	}
}
