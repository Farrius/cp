#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int par[MX], d[MX], c = 0;

pair<int, int> get (int x) {
	//si es parent devuelve el mismo i 0 
	if (par[x] == x) return make_pair(x, 0);
	//si ya esta conected con el par devuelve el par i 1
	if (par[par[x]] == x) {
		return make_pair(par[x], d[x]);
	}
	//habra dos o mas de distancia
	if (par[par[x]] != x) {
		auto obt = get(par[x]);
		par[x] = obt.first;
		d[x] += obt.second;
	}

	return make_pair(par[x], d[x]);
}

void unite (int x, int y) {
	par[x] = y;
	d[x]++;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			unite(x, y);
		} else {
			int z;
			cin >> z;
			auto zz = get(z);
			cout << zz.second << '\n';
		}
	}
}
