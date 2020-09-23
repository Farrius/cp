#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, x;
	cin >> n >> x;
	int ar[n];
	
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	int l = 0, r = 0;
	int sum = ar[0];
	int sol = 0;

	while (l < n && r < n) {
		if (sum < x) {
			r++;
			if (r == n) break;
			sum += ar[r];
		} else {
			if (sum == x) sol++;
			sum -= ar[l];
			l++;
		}
	}

	cout << sol << '\n';
}
