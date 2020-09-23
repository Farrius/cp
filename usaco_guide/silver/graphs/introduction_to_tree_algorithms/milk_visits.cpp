#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

vector<int> g[MX], component(MX);	
int n, m, label = 0;
string s;

void dfs (int v) {
	component[v] = label;

	for (auto x: g[v]) {
		if (component[x] || s[v] != s[x]) continue;
		dfs(x);
	}
}

int main () {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

	cin >> n >> m >> s;
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	for (int i = 0; i < n; i++) {
		if (component[i]) continue;
		label++;
		dfs(i);
	}

	while(m--) {
		int l, r;
		char c;
		cin >> l >> r >> c;
		l--; r--;
		if (s[l] == c || component[l] != component[r]) cout << 1;
		else cout << 0;
	}
	cout << '\n';
}
