#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		map<int, int> mp;
		bool puede = false;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			mp[cur]++;
		}
		for(int i = 0; i < m; i++){
			int cur;
			cin >> cur;
			if(mp[cur] >= 1 && !puede){
				cout << "YES" << '\n';
				cout << 1 << ' ' << cur << '\n';
				puede = true;
			}
		}
		if(!puede) cout << "NO" << '\n';
	}
}
