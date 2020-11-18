#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()
using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n], tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			tot += ar[i];
		}
		int sol = tot;
		for (int i = 0; i < (1<<n); i++) {
			int cur = 0;
			for (int j = 0; j < n; j++) {
				if ((i>>j) & 1) cur += ar[j];
			}
			sol = min(sol, max(tot - cur, cur));
		}
		cout << sol << '\n';
	}
}
