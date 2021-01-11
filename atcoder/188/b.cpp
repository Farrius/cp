#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n], br[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> br[i];
	}
	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += ar[i] * br[i];
	}
	if (tot == 0) cout << "Yes" << '\n';
	else cout << "No" << '\n';
}
