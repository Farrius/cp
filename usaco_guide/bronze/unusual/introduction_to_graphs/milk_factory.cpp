#include <bits/stdc++.h>

using namespace std;

const int MX = 1e2;

vector<int> g[MX];
bool buscando = true;
vector<bool> activo(MX);
int encuentra = 1;

void dfs(int v){
	activo[v] = true;
	for(auto x: g[v]){
		if(activo[x]) continue;
		encuentra++;
		dfs(x);
	}
}

int main() {
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[y].push_back(x);
	}
	
	for(int i = 0; i < n && buscando; i++){
		fill(activo.begin(), activo.end(), false);
		encuentra = 1;
		dfs(i);
		if(encuentra == n){
			cout << i + 1 << '\n';
			buscando = false;
		}
	}
	if(buscando) cout << -1 << '\n';
}
