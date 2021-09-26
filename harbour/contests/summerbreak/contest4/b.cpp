#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 305;

vector<int> ar(MX), l(MX), r(MX), segs;
int n, m, sol = 0;

int main () {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<int> use;
			int cur = ar[j] - ar[i];
			for (int k = 0; k < m; k++) {
				if ((i >= l[k] && i <= r[k]) && (j < l[k] || j > r[k])) {
					cur++;
					use.push_back(k + 1);
				}
			}

			if (cur > sol) {
				sol = cur;
				segs = use;
			}
		}
	}
	cout << sol << '\n';
	cout << (int) segs.size() << '\n';
	for (auto x : segs) {
		cout << x << ' ';
	}
	cout << '\n';
}
