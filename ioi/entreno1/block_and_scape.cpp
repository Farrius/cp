#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while (cin >> n) {
		int ar[n], br[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> br[i];
		}
		vector<pair<int, int>> cr;
		for (int i = 0; i < n; i++) {
			cr.emplace_back(ar[i], br[i]);
		}
		sort(cr.begin(), cr.end());
		vector<int> lis;
		for (auto x : cr) {
			int r = x.second;
			int in = upper_bound(lis.begin(), lis.end(), r) - lis.begin();
			if (in == (int) lis.size()) lis.push_back(r);
			else lis[in] = r;
		}
		cout << (int) lis.size() << '\n';
	}
}
