#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		map<int, int> mp;
		int x, y, z;
		cin >> x >> y >> z;
		mp[x]++;
		mp[y]++;
		mp[z]++;
		int maxi = max(x, max(y, z));
		int mini = min(x, min(y, z));
		if(mp[maxi] >= 2){
			cout << "YES" << '\n';
			cout << maxi << ' ' << mini << ' ' << mini << '\n';
		}else{
			cout << "NO" << '\n';
		}
	}
}
