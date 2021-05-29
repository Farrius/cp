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
	vector<int> pos(n + 1);
	for (int i = 0; i < n; i++) {
		pos[ar[i]] = i;
	}
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = pos[br[i]];
	}

	vector<int> lis;
	for (auto x : c) {
		int in = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
		if (in == (int) lis.size()) {
			lis.push_back(x);
		} else {
			lis[in] = x;
		}
	}
	cout << (int) lis.size() << '\n';
}
