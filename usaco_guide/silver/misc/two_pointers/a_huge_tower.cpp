#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 9;

int main () {
	int n, d;
	cin >> n >> d;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort(ar.begin(), ar.end());
	int r = 0, sol = 1;
	for (int l = 0; l < n; l++) {
		while (r < n - 1 && ar[r + 1] - ar[l] <= d) r++; 
		int dist = r - l + 1;
		sol = (sol * 1LL * dist) % MOD;
	}
	cout << sol << '\n';
}