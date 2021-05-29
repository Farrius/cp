#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		//si parejita ok los quitamos
		set<int> der, izq;
		vector<int> cnt_d(n + 1), cnt_i(n + 1);
		int sz_d = 0, sz_i = 0;
		for (int i = 0; i < l; i++) {
			int x;
			cin >> x;
			izq.insert(x);
			cnt_i[x]++;
			sz_i++;
		}
		for (int i = 0; i < r; i++) {
			int x;
			cin >> x;
			if (cnt_i[x] > 0) {
				cnt_i[x]--;
				sz_i--;
				if (cnt_i[x] == 0) izq.erase(x);
			} else {
				cnt_d[x]++;
				der.insert(x);
				sz_d++;
			}
		}
		//juntamos de colores distintos con prio para los solitarios
		int quitar = 0;
		vector<bool> vis(n + 1);
		vector<int> ar;
		if (sz_d > sz_i) {
			quitar = sz_i;
			for (auto x : der) {
				if (vis[x]) continue;
				vis[x] = true;
				ar.push_back(cnt_d[x]);
			}
		} else {
			quitar = sz_d;
			for (auto x : izq) {
				if (vis[x]) continue;
				vis[x] = true;
				ar.push_back(cnt_i[x]);
			}
		}
		int sol = quitar;
		for (auto &x : ar) {
			if (quitar == 0) break;
			if (x % 2) {
				x--;
				quitar--;
			}
		}
		for (auto &x : ar) {
			if (quitar == 0) break;
			int prev = x;
			x -= min(x, quitar);
			quitar -= min(quitar, prev);
		}
		//juntamos cambiando pie si es inpar se cambia color tmb y luego encontrar el otro
		for (auto x : ar) {
			sol += x/2;
			if (x % 2) sol++;
		}
		cout << sol << '\n';
	}
}
