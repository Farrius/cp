#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int div = 1;
		for(int i = 2; i * i <= n; i++){
			if(n % i == 0){
				div = i;
				break;
			}
		}
		if(div == 1) cout << n - 1 << ' ' << 1 << '\n';
		else cout << n/div << ' ' << n - (n/div) << '\n';
	}
}
