#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> g[n];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int sol = 0;
	for (auto adj: g) {
		sol = max(sol, (int) adj.size());
	}

	cout << sol + 1 << '\n';
}
