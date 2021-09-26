#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int sol = 0;
	vector<int> best;

	for (int k = 0; k < n; k++) {
		vector<int> cur(n);
		int curr = 0;
		cur[k] = ar[k];
		curr += ar[k];
		for (int i = k - 1; i >= 0; i--) {
			cur[i] = min(cur[i + 1], ar[i]);
			curr += cur[i];
		}
		for (int j = k + 1; j < n; j++) {
			cur[j] = min(cur[j - 1], ar[j]);
			curr += cur[j];
		}
		if (curr > sol) {
			sol = curr;
			best = cur;
		}
	}

	for (auto x : best) cout << x << ' ';
	cout << '\n';
}
