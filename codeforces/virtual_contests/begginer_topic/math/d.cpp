#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	if(c > 0){
		while(a < b){
			a += c;
		}
	}else if(c < 0){
		while(a > b){
			a += c;
		}
	}
	if(a == b) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
