#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> cnt;
		vector<int> pos(500);
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
			pos[x] = i;
		}
		for (auto x : cnt) {
			if (x.second == 1) {
				cout << pos[x.first] + 1 << '\n';
				break;
			}
		}
	}
}
