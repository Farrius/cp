#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, p;
	cin >> n >> p;
	int sol = -1;
	for (int i = 1; i < 32; i++) {
		int k = n - i * p;
		if (k < i) break;
		int cnt = 0;
		for (int j = 0; j < 32; j++) {
			if ((k>>j) & 1) cnt++;
		}
		if (cnt <= i) {
			sol = i;
			break;
		}
	}
	cout << sol << '\n';
}
