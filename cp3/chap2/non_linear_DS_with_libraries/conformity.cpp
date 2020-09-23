#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	while(cin >> n){
		if(n == 0) break;
		map<vector<int>, int> mp;
		for(int i = 0; i < n; i++){
			vector<int> v;
			for(int j = 0; j < 5; j++){
				int cur;
				cin >> cur;
				v.push_back(cur);
			}
			sort(v.begin(), v.end());
			mp[v]++;
		}
		int maxi = 0;
		for(auto x: mp){
			maxi = max(maxi, x.second);
		}
		int cnt = 0;
		for(auto x: mp){
			if(x.second == maxi) cnt += x.second;
		}
		cout << cnt << '\n';
	}
}
