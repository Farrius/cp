#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int n;
int ar[MX];
vector<int> sol(MX);

void fn (int l, int r, int c) {
	if (l > r) return;
	int in = -1, mx = -1;
	for (int i = l; i <= r; i++) {
		if (ar[i] > mx) {
			mx = ar[i];
			in = i;
		}
	}
	sol[in] = c;
	fn(l, in - 1, c + 1);
	fn(in + 1, r, c + 1);
}

int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		fn(0, n - 1, 0);
		for (int i = 0; i < n; i++) {
			cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		}
	}
}
