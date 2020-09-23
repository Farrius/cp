#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);

	int n;
	cin >> n;
	int ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort(ar, ar + n, greater<int>());

	int sol = n;

	for (int i = 0; i < n; i++) {
		if (ar[i] < i) {
			sol = i;
			break;
		}
	}
	cout << sol << '\n';
}
