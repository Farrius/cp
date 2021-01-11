#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;
		if (b > a) cout << "SENIL" << '\n';
		else cout << "CUERDO" << '\n';
	}
}
