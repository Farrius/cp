#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	vector<int> cnt(4);
	for (int i = 0; i < 4; i++) {
		cin >> cnt[i];
	}
	vector<int> last(4, -1);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		for (int j = 0; j < 5; j++) {
			int x;
			cin >> x;
			cur += x;
		}
		int change = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (cnt[i] == cnt[j]) {
					if (last[i] < last[j]) change = i;
					else change = j;
					break;
				}
			}
		}
		if (change == -1) {
			int mn = 1e9;
			for (int i = 0; i < 4; i++) {
				if (cnt[i] < mn) {
					mn = cnt[i];
					change = i;
				}
			}
		}
		last[change] = i;
		cnt[change] += cur;
	}
	for (auto x : cnt) cout << x << ' ';
	cout << '\n';
}
