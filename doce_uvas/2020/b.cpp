#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int aguanta = b * c;
		if (aguanta == a) cout << "AMBAS" << '\n';
		else if (aguanta < a) cout << "ENCENDIDOS" << '\n';
		else cout << "HORAS" << '\n';
	}
}
