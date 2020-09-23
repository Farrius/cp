#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	int n;
	cin >> n;
	int ma[n][n];
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < n; j++){
			ma[i][j] = s[j] == '1';
		}
	}

	int sol = 0;

	while(true){
		bool gucci = true;
		int y, x;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(ma[i][j]){
					gucci = false;
					y = i;
					x = j;
				}
			}
		}
		if(gucci) break;
		sol++;

		for(int i = y; i >= 0; i--){
			for(int j = x; j >= 0; j--){
				if(ma[i][j]) ma[i][j] = 0;
				else ma[i][j] = 1;
			}
		}

	}

	cout << sol << '\n';
}
