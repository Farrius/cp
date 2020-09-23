#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		bool puede = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int cur;
				cin >> cur;
				if(cur > 4){
					puede = false;
				}else if(cur > 3 && (i == 0 || i == n - 1 || j == 0 || j == m - 1)){
					puede = false;
				}else if((cur > 2) && ((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == m -1))){
					puede = false;
				}
			}
		}
		if(!puede){
			cout << "NO" << '\n';
		}else{
			cout << "YES" << '\n';
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == m -1)){
						cout << 2 << (j == m - 1 ? '\n' : ' ');
					}else if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
						cout << 3 << (j == m - 1 ? '\n' : ' ');
					}else{
						cout << 4 << (j == m - 1 ? '\n' : ' ');
					}
				}
			}
		}
	}
}
