#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for(auto &x: v){
		cin >> x.first >> x.second;
	}
	int sol = 0;
	for(int i = 0; i < n; i++){
		vector<int> cuenta(1000);
		for(int j = 0; j < n; j++){
			if(j == i) continue;
			for(int x = v[j].first; x < v[j].second; x++){
				cuenta[x] = 1;
			}
		}
		int cur = 0;
		for(auto x: cuenta) cur += x;
		sol = max(sol, cur);
	}
	cout << sol << '\n';
}
