#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool seq = false;
		int sol = 0;
		for(int i = 1; i <= n; i++){
			int cur;
			cin >> cur;
			if(cur != i){
				if(!seq){
					sol++;
					seq = true;
				}
			}else{
				seq = false;
			}
		}
		sol = min(sol, 2);
		cout << sol << '\n';
	}
}
