#include <bits/stdc++.h>

using namespace std;

vector<int> g[3001];
set<int> st;
vector<bool> visited(3001);
int vertex = 0;

void dfs (int v) {
	if (!st.count(v)) return;
	visited[v] = true;
	vertex++;
	for (auto x: g[v]) {
		if (visited[x]) continue;
		dfs(x);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int nS = n;
	visited.resize(n + 1);
	for (int i = 1; i <= n; i++) st.insert(i);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	while (n--) {
		vector<bool> vn(nS + 1);
		visited = vn;
		vertex = 0;
		dfs(*st.begin());
		if ((int) st.size() == vertex) cout << "YES" << '\n';
		else cout << "NO" << '\n';
		
		int v;
		cin >> v;
		st.erase(v);
	}
}
