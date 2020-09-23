#include <bits/stdc++.h>

using namespace std;

int n, ar[100000];

int solveMin (void) {
	if (ar[n - 2] - ar[0] == n - 2 && ar[n - 1] - ar[n - 2] > 2) return 2;
	if (ar[n - 1] - ar[1] == n - 2 && ar[1] - ar[0] > 2) return 2;

	int res = 0, j = 0;

	for (int i = 0; i < n; i++) {
		while (j < n - 1 && ar[j + 1] - ar[i] <= n - 1) j++;
		res = max(res, j - i + 1);
	}

	return n - res;
}

int main () {
	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	cin >>n;

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort (ar, ar + n);

	int mini = solveMin();
	int maxi = ar[n - 1] - ar[0] - min(ar[n - 1] - ar[n - 2], ar[1] - ar[0]) - (n - 2);

	cout << mini << '\n';
	cout << maxi << '\n';
}
