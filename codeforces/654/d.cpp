#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int ar[n][n];
		memset(ar, 0, sizeof(ar));
		if(k % n == 0){
			cout << 0 << '\n';
		}else{
			cout << 2 << '\n';
		}
		int tot = 0;
		for(int i = 0; i < n && tot < k; i++){
			int x = 0, y = i;
			for(int j = 0; j < n && tot < k; j++, tot++){
				ar[x][y] = 1;
				x = (x + 1) % n;
				y = (y + 1) % n;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << ar[i][j];
			}
			cout << '\n';
		}
	}
}
