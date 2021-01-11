#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	string a, b;
	while (cin >> a >> b) {
		int n = (int) a.size(), m = (int) b.size();
		int k = a[n - 1] - '0', l = b[m - 1] - '0';
		if ((l + 1) % 10 == k) cout << "FELIZ DECADA NUEVA" << '\n';
		else cout << "TOCA ESPERAR" << '\n';
	}
}
