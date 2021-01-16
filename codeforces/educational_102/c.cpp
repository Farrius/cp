#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int res = k - (n - k);
		vector<int> sol(k);
		iota(sol.begin(), sol.end(), 1);
		reverse(sol.begin() + res - 1, sol.end());
		for (int i = 0; i < k; i++) {
			cout << sol[i] << (i == k - 1 ? '\n' : ' ');
		}
	}
}
