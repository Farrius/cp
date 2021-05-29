#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e6 + 1;

int main () {
	int n;
	cin >> n;
	int sol = 0;
	for (int i = 1; i < n; i++) {
		int a = i;
		int b = n - i;
		sol++;
		while (a < b) {
			sol++;
			int c = b;
			b = a;
			a = c - a;
		}
	}
	cout << sol << '\n';
}

