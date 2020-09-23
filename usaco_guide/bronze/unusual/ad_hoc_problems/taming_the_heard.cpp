#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	a[0] = 0;
	int sol = 0;
	bool puede = true;

	for(int i = n - 1; i >= 0; i--){
		if(a[i] == -1) continue;
		int pasar = a[i];
		sol++;
		while(pasar){
			pasar--;
			i--;
			if(a[i] == -1) a[i] = pasar;
			if(a[i] != pasar) puede = false;
		}
	}
	int maxSol = sol;
	for(int x: a){
		if(x == -1) maxSol++;
	}

	if(!puede) cout << -1 << '\n';
	else cout << sol << ' ' << maxSol << '\n';
}
