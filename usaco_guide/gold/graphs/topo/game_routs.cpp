#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<int> g[MX], reverseG[MX], dp(MX, MOD), degree(MX);
int n, m;

void fn () {
	queue<int> q;
	for (int i = 0; i < n; i++) {

	}
}

int main () {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		degree[v]++;
		reverseG[v].push_back(u);
	}
	
	fn();
}
