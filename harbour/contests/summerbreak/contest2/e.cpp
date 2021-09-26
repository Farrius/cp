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
	int lis = 0, mx = -1;
	map<int, int> dp;
	for (int i = 0; i < n; i++) {
		int x = ar[i];
		dp[x] = dp[x - 1] + 1;
		if (dp[x] > lis) {
			lis = dp[x];
			mx = x;
		}
	}
	cout << lis << '\n';
	int obj = mx - lis + 1;
	for (int i = 0; i < n; i++) {
		if (ar[i] == obj) {
			cout << i + 1 << ' ';
			obj++;
		}
	}
	cout << '\n';
}
