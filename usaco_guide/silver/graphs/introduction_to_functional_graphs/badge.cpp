#include <bits/stdc++.h>

using namespace std;

const int MX = 1e3 + 3;
int p[MX], sol[MX];
bool vis[MX], u[MX];

int dfs (int node) {
	vis[node] = u[node] = true;

	if (u[p[node]]) {
		sol[node] = node;
		u[p[node]] = false;
		u[node] = false;

		return -1;
	} else if (vis[p[node]]) {
		u[node] = false;
		sol[node] = sol[p[node]];

		return sol[node];
	} else {
		int t = dfs (p[node]);

		if (t != -1) {
			sol[node] = t;
			u[node] = false;

			return sol[node];
		} else if (u[node]) {
			sol[node] = node;
			u[node] = false;

			return -1;
		} else {
			sol[node] = node;

			return sol[node];
		}
	}
}

int main () {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs (i);
		}
		cout << sol[i] << (i == n ? '\n' : ' ');
	}
}
