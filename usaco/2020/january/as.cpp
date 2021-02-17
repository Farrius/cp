#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	vector<set<int>> vis(n);
	for (int i = 0; i < n; i++) {
		ar[i] = i;
		vis[i].insert(i);
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		vis[ar[a]].insert(b);
		vis[ar[b]].insert(a);
		swap(ar[a], ar[b]);
	}
	//miramos el cycle
	vector<bool> ok(n);
	vector<int> sol(n);
	for (int i = 0; i < n; i++) {
		if (ok[i]) continue;
		vector<int> cur;
		set<int> cycle;
		int u = ar[i];
		while (!ok[u]) {
			ok[u] = true;
			cur.push_back(u);
			for (auto x : vis[u]) {
				cycle.insert(x);
			}
			u = ar[u];
		}
		int k = (int) cycle.size();
		for (auto x : cur) {
			sol[x] = k;
		}
	}
	//cout 
	for (int i = 0; i < n; i++) {
		cout << sol[i] << '\n';
	}
}
