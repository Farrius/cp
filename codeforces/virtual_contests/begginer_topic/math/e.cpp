#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(int k){
	ll res = 1;
	for(int i = 0; i < k; i++){
		res *= 2;
	}
	return res - 1;
}
int main(){
	int n, m;
	cin >> n >> m;
	int ma[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ma[i][j];
		}
	}
	ll sol = 0;
	for(int i = 0; i < n; i++){
		int b = 0, w = 0;
		for(int j = 0; j < m; j++){
			if(ma[i][j]) w++;
			else b++;
		}
		sol += power(b) + power(w);
	}
	for(int i = 0; i < m; i++){
		int b = 0, w = 0;
		for(int j = 0; j < n; j++){
			if(ma[j][i]) w++;
			else b++;
		}
		sol += power(b) + power(w);
	}
	cout << sol  - (m * n) << '\n';
}
