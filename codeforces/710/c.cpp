#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		int n = (int) a.size(), m = (int) b.size();
		int sol = n + m;
		for (int la = 0; la < n; la++) {
			for (int ra = 1; la + ra <= n; ra++) {
				for (int lb = 0; lb < m; lb++) {
					for (int rb = 1; lb + rb <= m; rb++) {
						string cura, curb;
						cura = a.substr(la, ra);
						curb = b.substr(lb, rb);
						if (cura == curb) {
							sol = min(sol, n + m - (int) cura.size() - (int) curb.size());
						}
					}
				}
			}
		}
		cout << sol << '\n';
	}
}
