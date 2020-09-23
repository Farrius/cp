#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m;
	while(cin >> n >> m){
		map<int, vector<int>> mp;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			mp[cur].push_back(i + 1);
		}
		while(m--){
			int k, v;
			cin >> k >> v;
			if(k > mp[v].size()){
				cout << 0 << '\n';
			}else{
				cout << mp[v][k - 1] << '\n';
			}
		}
	}
}
