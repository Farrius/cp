#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b;
	cin >> a >> b;
	if (a > b) {
		cout << 0 << '\n';
	} else {
		cout << b - a + 1 << '\n';
	}
}
