#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	if (c == 0) {
		if (a <= b) cout << "Aoki" << '\n';
		else cout << "Takahashi" << '\n';
	} else {
		if (b <= a) cout << "Takahashi" << '\n';
		else cout << "Aoki" << '\n';
	}
}
