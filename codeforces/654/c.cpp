#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll a, b, n, m;
		cin >> a >> b >> n >> m;
		if(a + b < n + m){
			cout << "No" << '\n';
		}else{
			if(min(a, b) < m){
				cout << "No" << '\n';
			}else{
				cout << "Yes" << '\n';
			}
		}
	}
}
