#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

vector<int> cur, g[MX];

int main () {
	int n, m;
	cin >> n >> m;
	int ar[n];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		ar[u] = v;
	}
	int a = 0, b = ar[a];
	while (a != b) {
		a = ar[a];
		b = ar[ar[b]];
	}
	a = 0;
	while (a != b) {
		a = ar[a];
		b = ar[b];
	}
	vector<int> cycle;
	set<int> ciclo;
	cycle.push_back(a);
	ciclo.insert(a);
	b = ar[a];
	while (b != a) {
		ciclo.insert(b);
		cycle.push_back(b);
		b = ar[a];
	}
	
	int q;
	cin >> q;
}
