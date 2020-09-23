#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	int n;
	cin >> n;
	int parent[n], to[n];
	memset(parent, 0, sizeof(parent));
	for (int i = 0; i < n; i++) {
		cin >> to[i];
		to[i]--;
		parent[to[i]]++;
	}

	int sol = n;
	queue<int> q;
		
	for (int i = 0; i < n; i++) {
		if (parent[i] == 0) {
			q.push(i);
			sol--;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (--parent[to[cur]] == 0) {
			q.push(to[cur]);
			sol--;
		}
	}

	cout << sol << '\n';
}
