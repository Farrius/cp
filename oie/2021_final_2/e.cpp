#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, m;
	cin >> n >> m;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int br[m];
	for (int i = 0; i < m; i++) {
		cin >> br[i];
	}
	int i = -1;
	for (auto f : br) {
		while (i < n - 1 && f >= ar[i + 1]) {
			f -= ar[i + 1];
			i++;
		}
	}
	cout << i + 1 << '\n';
}
