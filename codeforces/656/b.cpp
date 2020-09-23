#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> sol;
		int a[n * 2];
		for(int i = 0; i < n * 2; i++){
			cin >> a[i];
		}
		map<int, int> mp;
		for(int x: a){
			if(mp[x] >= 1) continue;
			else sol.push_back(x);
			mp[x]++;
		}
		for(auto x: sol) cout << x << ' ';
		cout << '\n';
	}
}
