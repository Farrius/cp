#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll l, r, m;
		cin >> l >> r >> m;
		for(ll a = l; a <= r; a++){
			ll mod = m % a;
			ll hasta = a - mod;
			if(r - l >= mod && m - r + (r - mod) != 0){
				cout << a << ' '<< r << ' '<< r - mod << '\n';
				break;
			}
			if(r - l >= hasta){
				cout << a << ' ' << r - hasta << ' ' << r << '\n';
				break;
			}
		}
	}
}
