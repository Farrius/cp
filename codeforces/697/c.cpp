#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, k;
		cin >> a >> b >> k;
		vector<int> cnta(a + 1), cntb(b + 1);
		int ar[k], br[k];
		for (int i = 0; i < k; i++) {
			cin >> ar[i];
			cnta[ar[i]]++;
		}
		for (int i = 0; i < k; i++) {
			cin >> br[i];
			cntb[br[i]]++;
		}
		ll sol = 0;
		int vistas = 0;
		vector<int> visa(a + 1), visb(b + 1);
		for (int i = 0; i < k; i++) {
			sol += (k - cnta[ar[i]] - cntb[br[i]] + 1);
			sol -= (vistas - visa[ar[i]] - visb[br[i]]);
			vistas++;
			visa[ar[i]]++;
			visb[br[i]]++;
		}
		cout << sol << '\n';
	}
}
