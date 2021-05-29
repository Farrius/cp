#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		tot += ar[i];
	}
	ll cur = 0;
	for (int i = 0; i < n; i++) {
		tot -= ar[i];
		cur += ar[i];
		if (tot == cur) {
			cout << i + 1 << '\n';
			return 0;
		}
	}

	cout << "No existe" << '\n';

}
