#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	sort (ar, ar + n);

	int index = 0;
	vector<int> sol(n);

	for (int i = 1; i < n; i += 2) {
		sol[i] = ar[index++];
	}

	for (int i = 0; i < n; i += 2) {
		sol[i] = ar[index++];
	}

	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1) continue;
		if (sol[i] < sol[i + 1] && sol[i] < sol[i - 1]) tot++;
	}

	cout << tot << '\n';

	for (int i = 0; i < n; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
	}
}
