#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
 
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int c[n], a[n], b[n];
		ll sol = 0;
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		for (int i = 0; i < n; i++) {
			if (b[i] < a[i]) swap(b[i], a[i]);
		}
		//llevar el graph, parar cuando se junta y calc si termina en linea
		ll acc = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] == b[i]) {
			       	acc = 0;
			} else if (acc < b[i] - a[i]) {
				sol = max(sol, acc + c[i] - 1);
				acc = b[i] - a[i];
			}
			acc += 2;
			sol = max(sol, acc + c[i] - 1);
			acc += ((i == n - 1) ? 0 : (a[i + 1] - 1) + (c[i] - b[i + 1]));
		}
		cout << sol << '\n';
	}
}
