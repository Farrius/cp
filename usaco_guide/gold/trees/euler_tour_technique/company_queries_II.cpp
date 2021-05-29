#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

struct rmq {
	vector<int> v;
	vector<vector<int>> jmp;

	int comb (int a, int b) {
		if (v[a] == v[b]) {
			return min(a, b);
		} else {
			return v[a] < v[b] ? a : b;
		}
	}

	void init (vector<int>& _v) {
		v = _v;
		int m = (int) v.size();
		jmp = {vector<int>(m)};
		iota(jmp[0].begin(), jmp[0].end(), 0);
		
		for (int j = 1; (1<<j) <= m; j++) {
			jmp.push_back(vector<int>(m - (1<<j) + 1));
			for (int i = 0; i < (int) jmp[j].size(); i++) {
				jmp[j][i] = comb(jmp[j - 1][i], jmp[j - 1][i + (1<<(j - 1))]);
			}
		}
	}

	int level (int x) {return 31 - __builtin_clz(x);}

	int index (int l, int r) {
		int d = level(r - l + 1);
		return comb(jmp[d][l], jmp[d][r - (1<<d) + 1]);
	}

	int query (int l, int r) {
		return v[index(l, r)];
	}
};

const int MX = 2e5 + 5;

vector<int> g[MX], et(MX * 4);

int timer = 0, d[MX];

void dfs (int u, int p) {
	d[u] = timer;
	et[timer++] = u;
	for (auto v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		et[timer++] = u;
	}
}

int main () {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		x--;
		g[x].push_back(i + 1);
	}
	dfs(0, -1);
	//for (auto x : et) {
	//	cout << x << ' ';
	//}
	//cout << '\n';
	rmq rm;
	rm.init(et);
	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		int x = d[a], y = d[b];
		if (x > y) swap(x, y);
		cout << rm.query(x, y) + 1 << '\n';
	}
}
