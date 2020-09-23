#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	int x, y, m;
	cin >> x >> y >> m;
	int sol = 0;
	for(int i = 0; i <= m; i += x){
		for(int j = 0; j + i <= m; j += y){
			sol = max(sol, j + i);
		}
		sol = max(sol, i);
	}
	cout << sol << '\n';
}
