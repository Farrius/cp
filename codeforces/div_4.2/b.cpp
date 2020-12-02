#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int st = 0, en = 0, last = 0;
	for (int i = 0; i < n; i++) {
		st++;
		last = i;
		if (i < n && ar[i + 1] < ar[i]) break;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i <= last) break;
		en++;
		if ((i > 0 && ar[i - 1] < ar[i])) break;
	}
	cout << st + en << '\n';
}
