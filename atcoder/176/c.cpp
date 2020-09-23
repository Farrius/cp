#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) -1);

int main () {
	ll sol = 0;
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	for (int i = 1; i < n; i++) {
		if (ar[i] < ar[i - 1]) {
			sol += ar[i - 1] - ar[i];
			ar[i] = ar[i - 1];
		}
	}

	cout << sol << '\n';
}
