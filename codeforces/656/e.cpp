#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
	
vector<vector<int>> g;
vector<bool> used;
vector<int> ord;

void dfs(int v){
	used[v] = true;
	for(auto hacia : g[v]){
		if(!used[hacia]) dfs(hacia);
	}

	ord.push_back(v);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		g = vector<vector<int>>(n);
		vector<pair<int, int>> edges;
		for(int i = 0; i < m; i++){
			int ty, a, b;
			cin >> ty >> a >> b;
			a--;
			b--;
			if(ty == 1){
				g[a].push_back(b);
			}
			edges.push_back({a, b});
		}
		ord.clear();
		used = vector<bool>(n);
		for(int i = 0; i < n; i++){
			if(!used[i]) dfs(i);
		}

		reverse(ord.begin(), ord.end());

		vector<int> topo(n);
		for(int i = 0; i < n; i++){
			topo[ord[i]] = i;
		}

		bool puede = true;
		for(int i = 0; i < n; i++){
			for(auto j : g[i]){
				if(topo[i] > topo[j]) puede = false;
			}
		}

		if(!puede){
			cout << "NO" << '\n';
		}else{
			cout << "YES" << '\n';
			for(auto x : edges){
				if(topo[x.first] < topo[x.second]) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
				else cout << x.second + 1 << ' ' << x.first + 1 << '\n';
			}
		}
	}
}
