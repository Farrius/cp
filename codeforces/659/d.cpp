#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;

map<int, int> utilizados;

void ver_bits(int n){
	for(int i = 0; i < 31; i++){
		if((n>>i) & 1) utilizados[i]++;
	}
	return;
}
	
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		utilizados.clear();
		int cur_xor = 0;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			ver_bits(cur);
			cur_xor ^= cur;
		}
		if(cur_xor == 0){
			cout << "DRAW" << '\n';
			continue;
		}

		if(n % 2 == 0){
			cout << "WIN" << '\n';
		}else{
			for(int i = 30; i >= 0; i--){
				if(utilizados[i] % 2){

					if(utilizados[i] % 4 == 3) cout << "LOSE" << '\n';
					else cout << "WIN" << '\n';

					break;
				}
			}
		}
	}
}
