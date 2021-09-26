#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, x;
	cin >> n >> x;
	int ar[n];
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (i % 2) ar[i]--;
		tot += ar[i];
	}
	if (tot <= x) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
