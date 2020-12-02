#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		map<int, int> mp;
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			mp[ar[i]]++;
		}
		int sol = -1;
		for (auto x : mp) {
			if (x.second == 1) {
				sol = x.first;
				break;
			}
		}
		int res = -1;
		for (int i = 0; i < n; i++) {
			if (ar[i] == sol) {
				res = i + 1;
				break;
			}
		}
		cout << res << '\n';
	}
}
