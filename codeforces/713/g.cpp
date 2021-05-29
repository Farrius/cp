#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e7 + 1;

int divs[MX], sol[MX];

int main () {
	memset(sol, -1, sizeof(sol));
	for (int i = 1; i < MX; i++) {
		for (int j = i; j < MX; j += i) {
			divs[j] += i;
		}
	}

	for (int i = MX - 1; i >= 1; i--) {
		if (divs[i] <= MX) {
			sol[divs[i]] = i;
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		cout << sol[c] << '\n';
	}
}
