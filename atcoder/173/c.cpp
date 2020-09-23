#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	char matrix[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> matrix[i][j];
		}
	}
	int sol = 0;
	for(int i = 0; i < (1<<n); i++){
		for(int j = 0; j < (1<<m); j++){
			int cnt = 0;
			for(int row = 0; row < n; row++){
				if(!((i >> row) & 1)) continue;
				for(int col = 0; col < m; col++){
					f(!((j >> col) & 1)) continue;
					if(matrix[row][col] == '#') cnt++;
				}
			}
			if(cnt == k) sol++;
		}

	}
	cout << sol << '\n';
}
