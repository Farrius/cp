#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("greedy.in", "r", stdin);
	freopen("greedy.out", "w", stdout);

	int n;
	cin >> n;
	int c[n];

	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		c[i] = n - d;
	}

	int lo = 1, hi = n + 1;
	while (lo  + 1 < hi) {
		int mid = lo + (hi - lo)/2;
		vector<int> num(n + 1);
		bool ok = true;

		for (int i = 0; i < mid - 1; i++) {
			num[c[i]]++;
		}

		int total = 0;
		
		for (int i = 1; i <= n; i++) {
			total += num[i];
			if (total >= i) ok = false;
		}

		if (ok) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	
	int ans = lo;

	cout << n - lo << '\n';
}
