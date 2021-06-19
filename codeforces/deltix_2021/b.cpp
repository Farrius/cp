#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e3 + 5;

vector<pair<int, pair<int, int>>> sol;

void fn1 (int a, int b) {
	a++; b++;
	sol.push_back(make_pair(2, make_pair(a, b)));
	sol.push_back(make_pair(1, make_pair(a, b)));
	sol.push_back(make_pair(1, make_pair(a, b)));
	sol.push_back(make_pair(2, make_pair(a, b)));
	sol.push_back(make_pair(1, make_pair(a, b)));
	sol.push_back(make_pair(1, make_pair(a, b)));
}


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		sol.clear();
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}

		for (int i = 1; i < n; i += 2) {
			fn1(i - 1, i);
		}

		cout << (int) sol.size() << '\n';
		for (auto cur : sol) {
			cout << cur.first << ' ';
			cout << cur.second.first << ' ' << cur.second.second << '\n';
		}
	}
}
