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
		int suma = 30;
		set<int> st = {6, 10, 14};
		if(n <= 30){
			cout << "NO" << '\n';
		}else{
			int res = n - suma;
			if(st.count(res)){
				suma += 1;
				if(suma >= n){
					cout << "NO" << '\n';
				}else{
					cout << "YES" << '\n';
					cout << "6 10 15 " << n - suma << '\n';
				}
			}else{
				cout << "YES" << '\n';
				cout << "6 10 14 " << res << '\n';
			}
		}
	}
}
