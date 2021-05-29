#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, w;
		cin >> n >> w;
		vector<int> doses(25);
		ll tot = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			tot += x;
			int base = -1;
			while (x) {
				base++;
				x /= 2;
			}
			doses[base]++;
		}
		int sol = 0;
		while (tot > 0) {
			int cur = w;
			for (int i = 24; i >= 0 && cur > 0; i--) {
				if (doses[i] == 0) continue;
				int quita = cur/(1<<i);
				quita = min(quita, doses[i]);
				int num = quita * (1<<i);
				doses[i] -= quita;
				cur -= num;
				tot -= num;
			}
			sol++;
		}
		cout << sol << '\n';
	}
}
