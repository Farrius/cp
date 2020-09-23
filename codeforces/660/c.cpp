#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

vector<int> g[MX];

int p[MX], h[MX], personas[MX], felizes[MX];

bool ok;

void dfs(int v, int ancestor = -1) {
	personas[v] = p[v];
	int felizesCur = 0;

	for (auto hacia: g[v]) {
		if (hacia == ancestor) continue;
		dfs(hacia, v);
		felizesCur += felizes[hacia];
		personas[v] += personas[hacia];
	}

	felizes[v] = (personas[v] + h[v])/2;

	if ((personas[v] + h[v]) % 2) ok = false;
	if (felizes[v] < 0 || felizes[v] > personas[v]) ok = false;
	if (felizesCur > felizes[v]) ok = false;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		ok = true;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		dfs(0);

		cout << (ok ? "YES" : "NO") << '\n';

		for(int i = 0; i < n; i++) g[i].clear();
	}
}
