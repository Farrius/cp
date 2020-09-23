#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);
	int n;
	string s;
	cin >> n >> s;
	for(int i = 1; i <= n; i++){
		map<string, int> occ;
		bool puede = true;
		for(int j = 0; j + i <= n; j++){
			string cur;
			cur = s.substr(j, i);
			occ[cur]++;
			if(occ[cur] > 1){
				puede = false;
			}
		}
		if(!puede) continue;
		for(auto x: occ){
			if(x.second == 1){
				cout << i << '\n';
				return 0;
			}
		}
	}
}
