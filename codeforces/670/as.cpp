#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int t;
	cin >> t;
	while (t--) {
		vector<int> cnt(101);
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}

		int queda = 2;
		int sol = 0;

		for (int i = 0; i < 102 && queda > 0; i++) {
			if (cnt[i] == 0) {
				if (queda == 2) {
					queda -= 2;
					sol += (i * 2);
				} else {
					queda--;
					sol += i;
				}
			} else if (cnt[i] == 1 && queda == 2) {
				queda--;
				sol += i;
			}
		}

		cout << sol << '\n';
	}
}

