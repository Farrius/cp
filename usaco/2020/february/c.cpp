#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ma[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
		}
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ma[i][j] < 100) continue;
			bool cien[n];
			memset(cien, false, sizeof(cien));
			int mx_x = n;
			for (int y = i; y < n; y++) {
				if (ma[y][j] < 100) break;
				for (int x = j; x < mx_x; x++) {
					if (ma[y][x] < 100) {
						mx_x = min(mx_x, x);
						break;
					}
					if (ma[y][x] == 100) cien[x] = true;
					if (x > 0 && cien[x - 1]) cien[x] = true;
					if (cien[x]) sol++;
				}
			}
		}
	}
	cout << sol << '\n';
}
