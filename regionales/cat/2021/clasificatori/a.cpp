#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		ld ar[n];
		ld tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		tot /= n;
		bool ok = true;
		for (int i = 0; i < n; i++) {
			if (ar[i] > tot) {
				cout << "si" << '\n';
				ok = false;
				break;
			}
		}
		if (ok) cout << "no" << '\n';
	}
}
