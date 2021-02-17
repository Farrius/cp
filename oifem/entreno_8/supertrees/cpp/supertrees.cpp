#include "supertrees.h"
#include <vector>

using namespace std;

struct DSU {
	vector<int> e;
	void init (int n) {e = vector<int>(n, -1);}
	int get (int x) {return e[x] < 0 ? x : e[x] = get(e[x]);}
	bool sameSet (int x, int y) {return get(x) == get(y);}
	bool unite (int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};

int construct(vector<vector<int>> p) {
	//take input
	int n = p.size();
	vector<vector<int>> sol(n, vector<int>(n));
	DSU dsu;
	dsu.init(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] >= 1) {
				dsu.unite(i, j);
			}
		}
	}
	//comprovar si ok
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (p[i][j] == 0 && dsu.sameSet(i, j)) return 0;
		}
	}
	//crear graph con los componentes creados
	vector<int> g[n];
	for (int i = 0; i < n; i++) {
		int par = dsu.get(i);
		g[par].push_back(i);
	}
	//crear para cada grupo
	for (int i = 0; i < n; i++) {
		int m = (int) g[i].size();
		if (m == 0) continue;
		DSU deuna;
		deuna.init(m);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				if (p[g[i][j]][g[i][k]] == 1) {
					deuna.unite(j, k);
				}
			}
		}
		set<int> grupos;
	}
	//ajustar la sol
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sol[i][j] == 1) sol[j][i] = 1;
		}
	}
	//output
	build(sol);
	return 1;
}
