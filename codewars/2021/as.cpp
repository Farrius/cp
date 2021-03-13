#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	bool ok = false;
	for (int i = 0; i <= 50623 && !ok; i++) {
		for (int j = 0; j <= 50623 && !ok; j++) {
			if (a * i + b * j == c) {
				for (int k = 0; k < i; k++) {
					cout << "TOC" << '\n';
				}
				for (int k = 0; k < j; k++) {
					cout << "BUM" << '\n';
				}
				ok = true;
			}
		}
	}
	if (!ok) cout << c << '\n';
}
