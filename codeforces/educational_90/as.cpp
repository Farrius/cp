#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll a, b, c;
		cin >> a >> b >> c;
		if(a >= c){
			cout << -1 << ' ';
		}else{
			cout << 1 << ' ';
		}
		if(b * a <= c){
			cout << -1 << '\n';
		}else{
			cout << b << '\n';
		}
	}
}
