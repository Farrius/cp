#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool neg = true;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			if(i % 2 == 0){
				if(cur < 0) cur = -cur;
			}else{
				if(cur > 0) cur = -cur;
			}
			cout << cur << (i == n - 1 ? '\n' : ' ');
		}
	}
}
