#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	map<ll, ll> mp;
	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t == 0){
			ll k, v;
			cin >> k >> v;
			mp[k] = v;
		}else{
			ll k;
			cin >> k;
			cout << mp[k] << '\n';
		}
	}
}
