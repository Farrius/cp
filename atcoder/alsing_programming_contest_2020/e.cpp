#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int sol = INT_MIN;
	for(int i = 0; i < (1<<25); i++){
		vector<vector<int>> a(25,vector<int>(25, 0));
		int cur = 0;
		for(int j = 0; j < 25; j++){
			if((i>>j) & 1){
				a[0][j] = 1;
				cur++;
			}
		}
		for(int v = 1; v < 25; v++){
			int len = 25 - v;
			for(int u = 0; u < len; u++){
				a[v][u] = a[v - 1][u] + a[v - 1][u + 1];
				if(a[v][u] % 2) cur++;
			}
		}
		sol = max(sol, cur);
	}
	cout << sol << '\n';
}
