#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	while (n--) {
		ll i, j;
		cin >> i >> j;
		if (j == 0) {
			if (i <= 1) cout << "Verdadero" << '\n';
			else cout << "Falso" << '\n';
			continue;
		}
		if (j * 2 >= i - 1) cout << "Verdadero" << '\n';
		else cout << "Falso" << '\n';
	}
}
