#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<int> prv(n), nxt(n);
		iota(prv.begin(), prv.end(), -1);
		iota(nxt.begin(), nxt.end(), 1);
		prv[0] = n - 1;
		nxt[n - 1] = 0;

		set<int> quitar;
		for (int i = 0; i < n; i++) {
			if (__gcd(ar[prv[i]], ar[i]) == 1) {
				quitar.insert(i);
			}
		}
		vector<int> sol;
		for (int cur = 0; (int) sol.size() < n && !quitar.empty();) {
			auto it = quitar.upper_bound(cur);
			if (it == quitar.end()) it = quitar.begin();
			int x = *it;
			sol.push_back(x);
			quitar.erase(x);
			if (nxt[x] == x) break;
			quitar.erase(nxt[x]);
			nxt[prv[x]] = nxt[x];
			prv[nxt[x]] = prv[x];
			if (__gcd(ar[prv[x]], ar[nxt[x]]) == 1) quitar.insert(nxt[x]);
			cur = nxt[x];
		}
		cout << (int) sol.size() << ' ';
		for (int i = 0; i < (int) sol.size(); i++) {
			cout << sol[i] + 1 << ' ';
		}
		cout << '\n';
	}
}
