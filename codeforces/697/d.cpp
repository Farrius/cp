#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 2e5 + 5;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> un, dos;
		int ar[n], br[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> br[i];
		}
		for (int i = 0; i < n; i++) {
			if (br[i] == 1) un.push_back(ar[i]);
			else dos.push_back(ar[i]);
		}
		sort(un.begin(), un.end(), greater<int>());
		sort(dos.begin(), dos.end(), greater<int>());
		int k = (int) un.size();
		vector<ll> pref(k + 1);
		for (int i = 1; i <= k; i++) {
			pref[i] = pref[i - 1] + un[i - 1];
		}
		int sol = 4e5 + 5;
		int j = 0;
		ll other = 0;
		for (int i = 0; i <= k; i++) {
			if (i == 0) {
				while (j < (int) dos.size() && other < m) {
					other += dos[j];
					j++;
				}
			} 
			while (j > 0 && other - dos[j - 1] + pref[i] >= m) {
				other -= dos[j - 1];
				j--; 
			}
			if (other + pref[i] >= m) {
				sol = min(sol, j * 2 + i);
			}
		}
		if (sol == 4e5 + 5) cout << -1 << '\n';
		else cout << sol << '\n';
	}
}
