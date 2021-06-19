#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		int tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tot += x;
		}
		vector<int> moni = {1, 2, 5, 10, 20, 50, 100, 200};
		reverse(moni.begin(), moni.end());
		int mn = 0;
		for (auto x : moni) {
			while (tot >= x) {
				tot -= x;
				mn++;
			}
		}
		if (mn == n || mn == n - 1) cout << "si" << '\n';
		else cout << "no" << '\n';
	}
}
