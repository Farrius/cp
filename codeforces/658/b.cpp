#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int sol = -1;
		bool gana = true, para = false;
		for(int i = 0; i < n; i++){
			int cur; 
			cin >> cur;
			if(cur == 1 && !para){
				gana = !gana;
			}else{
				sol = gana;
				para = true;
			}
		}
		if(sol == -1) sol = !gana;
		cout << (sol % 2 ? "First" : "Second") << '\n';
	}
}
