#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for (int i = 0; i < 3e5 + 1; i++) {
		mp[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	int sol = 0;
	int x = k;
	for (auto cur : mp) {
		if (x == 0) {
			break;
		} if (cur.second == 0) {
			sol += cur.first * x;
			break;
		} else if (cur.second < x) {
			int quita = x - cur.second;
			sol += quita * cur.first;
			x -= quita;
		}
	}
	cout << sol << '\n';
}
