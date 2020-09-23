#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	int t;
	cin >> t;
	while(t--){
		ll n, r;
		cin >> n >> r;
		ll hasta = min(n, r);
		ll sol = pow(hasta, 2) + hasta;
		sol = (sol % 2) + (sol/2);
		if(n <= r){
			sol -= hasta;
			sol++;
		}
		cout << sol << '\n';
	}
}
