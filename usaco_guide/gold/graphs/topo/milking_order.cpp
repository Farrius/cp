#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int n, m;
vector<int> sol(MX), observations[50000], perm;

bool fn (int mid) {
	perm.clear();
	//make graph
	vector<int> g[n], degree(n);
	for (int i = 0; i < mid; i++) {
		for (int j = 1; j < (int) observations[i].size(); j++) {
			g[observations[i][j - 1]].push_back(observations[i][j]);
			degree[observations[i][j]]++;
		}
	}
	//khans algorithm
	bool cycle = false;
	priority_queue<int> q;
	for (int i = 0; i < n; i++) {
		if (degree[i] == 0) q.push(-i);
	}
	for (int i = 0; i < n; i++) {
		if (q.empty()) return false;
		int v = -q.top();
		q.pop();
		perm.push_back(v);
		for (int u : g[v]) {
			degree[u]--;
			if (degree[u] == 0) q.push(-u);
		}
	}

	return true;
}

int main () {
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	//take input
	cin >> n >> m;
	sol.resize(n);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			x--;
			observations[i].push_back(x);
		}
	}
	//binary search
	int lo = 1, hi = m;
	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		if (fn(mid)) {
			lo = mid + 1;
			sol = perm;
		} else {
			hi = mid - 1;
		}
	}
	//print sol
	for (int i = 0; i < n; i++) {
		cout << sol[i] + 1 << (i == n - 1 ? '\n' : ' ');
	}
}
