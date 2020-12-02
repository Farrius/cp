#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	cout << 4 * (n + 1) - n << '\n';
	int j = 0;
	cout << 0 << ' ' << n + 1 << '\n';
	cout << 1 << ' ' << n + 1 << '\n';
	for (int i = n; i >= 1; i--) {
		cout << j << ' ' << i << '\n';
		cout << j + 1 << ' ' << i << '\n';
		cout << j + 2 << ' ' << i << '\n';
		j++;
	}
	cout << n << ' ' << 0 << '\n';
	cout << n + 1 << ' ' << 0 << '\n';
}
