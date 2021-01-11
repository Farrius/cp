#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
const int MX = 2505;

int pref[MX][MX];

bool cmp (const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int suma (int x1, int y1, int x2, int y2) {
	return pref[x2 + 1][y2 + 1] - pref[x1][y2 + 1] - pref[x2 + 1][y1] + pref[x1][y1];
}
int main () {
	//compress
	int n;
	cin >> n;
	pair<int, int> ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i].first >> ar[i].second;
	}
	sort(ar, ar + n);
	for (int i = 0; i < n; i++) {
		ar[i].first = i + 1;
	}
	sort(ar, ar + n, cmp);
	for (int i = 0; i < n; i++) {
		ar[i].second = i + 1;
	}
	for (int i = 0; i < n; i++) {
		pref[ar[i].first][ar[i].second] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	ll sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int x1 = min(ar[i].first, ar[j].first) - 1;
			int x2 = max(ar[i].first, ar[j].first) - 1;
			sol += suma(0, i, x1, j) * suma(x2, i, n - 1, j);
		}
	}
	cout << sol + 1 << '\n';
}
