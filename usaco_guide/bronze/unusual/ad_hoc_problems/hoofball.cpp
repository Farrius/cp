#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);

	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	vector<bool> canvio(n, false);
	canvio[0] = true;
	for(int i = 1; i < n - 1; i++){
		if(a[i] - a[i - 1] > a[i + 1] - a[i]){
			canvio[i] = true;
		}
	}

	int ans = 0, i = 0;

	while(i < n){
		int rCambio = 0, lCambio = 0;
		while(i < n && canvio[i]){
			i++;
			rCambio++;
		}
		while(i < n && !canvio[i]){
			i++;
			lCambio++;
		}
		if(rCambio > 1 && lCambio > 1){
			ans += 2;
		}else{
			ans++;
		}
	}

	cout << ans << '\n';
}
