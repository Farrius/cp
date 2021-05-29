#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int ar[26];
int n;

ll fn (int i, ll u, ll d) {
	if (i == n) {
		return abs(u - d);
	}
	return min(fn(i + 1, u + ar[i], d), fn(i + 1, u, d + ar[i]));
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	cout << fn(0, 0, 0) << '\n';
}
