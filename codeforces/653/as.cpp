#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int x, y, n;
		cin >> x >> y >> n;
		int cur_mod = n % x;
		if(cur_mod == y){
			cout << n << '\n';
		}else if(cur_mod > y){
			int res = cur_mod - y;
			cout << n - res << '\n';
		}else{
			int res = cur_mod;
			res += x - y;
			cout << n - res << '\n';
		}
	}
}
