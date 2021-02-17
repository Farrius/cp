#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	while (cin >> n >> m) {
		int ar[n], gran[m];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		sort(ar, ar + n);
		for (int i = 0; i < m; i++) {
			cin >> gran[i];
		}
		sort(gran, gran + m);
		int i = 0, j = 0, sol = 0;
		while (i < n) {
			while (j < m && ar[i] > gran[j]) j++;
			if (j == m) {
				sol += n - i;
				break;
			}
			if (ar[i] == gran[j]) {
				i++;
				j++;
			} else if (ar[i] + 1 == gran[j]) {
				i++; 
				j++;
			} else {
				sol++;
				i++;
			}
		}
		cout << sol << '\n';
	}
}
