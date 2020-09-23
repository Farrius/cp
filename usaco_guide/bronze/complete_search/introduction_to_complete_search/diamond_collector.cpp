#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int sol = INT_MIN;
	for(int i = 0; i < n; i++){
		int cur_sol = 0;
		for(int j = 0; j < n; j++){
			if(a[i] + k >= a[j] && a[j] >= a[i]) cur_sol++;
		}
		sol = max(sol, cur_sol);
	}
	cout << sol << '\n';
}
