#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, s, f;
	cin >> n >> s >> f;
	s--; f--;
	int mat[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	vector<int> dist(n, 1e9);
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		if (u == f) {
			cout << dist[f] << '\n';
			return 0;
		}
		q.pop();
		for (int i = 0; i < n; i++) {
			if (mat[u][i]) {
				if (dist[i] != 1e9) continue;
				q.push(i);
				dist[i] = dist[u] + 1;
			}
		}
	}
	cout << 0 << '\n';
}
