#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;
	n++;
	vector<int> ar(n);
	for (int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	sort(ar.begin(), ar.end());
	ll sol = 12 - (ar[n - 1] % 12);
	vector<int> resto;
	for (int i = 1; i < n; i++) {
		int dist = ar[i] - ar[i - 1];
		sol += dist;
		int portal = (ar[i] % 12) + 12 - (ar[i - 1] % 12 == 0 ? 12 : ar[i - 1] % 12);
		resto.push_back(portal - dist);
	}
	sort(resto.begin(), resto.end());
	int m = min(k - 1, (int) resto.size());
	for (int i = 0; i < m; i++) {
		if (resto[i] > 0) break;
		sol += resto[i];
	}
	cout << sol << '\n';
}
