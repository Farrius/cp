#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		if (cur == x) continue;
		cout << cur << ' ';
	}
	cout << '\n';
}
