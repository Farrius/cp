#include <bits/stdc++.h>

using namespace std;

int a[64];
int s[500][50], p[500][50];
int n, m;

bool ok(int i, int j, int k){
	bool si = true;
	for(int it = 0; it < n; it++){
		a[16 * s[it][i] + 4 * s[it][j] + s[it][k]] = 1;
	}
	for(int it = 0; it < n; it++){
		if(a[16 * p[it][i] + 4 * p[it][j] + p[it][k]]) si = false;
	}
	for(int it = 0; it < n; it++){
		a[16 * s[it][i] + 4 * s[it][j] + s[it][k]] = 0;
	}
	return si;
}

int main(){
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	cin >> n >> m;
	string spotty[n], plain[n];
	for(int i = 0; i < n; i++){
		cin >> spotty[i];
		for(int j = 0; j < m; j++){
			if(spotty[i][j] == 'A') s[i][j] = 0;
			if(spotty[i][j] == 'C') s[i][j] = 1;
			if(spotty[i][j] == 'G') s[i][j] = 2;
			if(spotty[i][j] == 'T') s[i][j] = 3;
		}
	}
	for(int i = 0; i < n; i++){
		cin >> plain[i];
		for(int j = 0; j < m; j++){
			if(plain[i][j] == 'A') p[i][j] = 0;
			if(plain[i][j] == 'C') p[i][j] = 1;
			if(plain[i][j] == 'G') p[i][j] = 2;
			if(plain[i][j] == 'T') p[i][j] = 3;
		}
	}
	int sol = 0;

	for(int i = 0; i < m; i++){
		for(int j = i + 1; j < m; j++){
			for(int k = j + 1; k < m; k++){
				if(ok(i, j, k)) sol++;
			}
		}
	}
	cout << sol << '\n';
}
