#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 8;
int n, k, sol = 0;
int ma[MX][MX];

void backtrack (int i, int cur, int state) {
	if (state == (1<<n) - 1 && cur + ma[i][0] == k) {
		sol++;
		return;
	}
	for (int j = 0; j < n; j++) {
		if ((state>>j) & 1) continue;
		backtrack(j, cur + ma[i][j], (state|(1<<j)));
	}
}

int main () {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ma[i][j];
		}
	}
	backtrack(0, 0, 1);
	cout << sol << '\n';
}
