#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ochos = (n - 1)/4 + 1;
		for(int i = 0; i < (n - ochos); i++){
			cout << '9';
		}
		for(int i = 0; i < ochos; i++){
			cout << '8';
		}
		cout << '\n';
	}
}
