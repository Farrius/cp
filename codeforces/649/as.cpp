#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;
		int a[n];
		ll tot = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			tot += a[i];
		}
		int tmp_tot = tot;
		int sol = 0;
		int cur = n;
		int i = n - 1;
		while(tmp_tot % x == 0 && cur > 0){
			tmp_tot -= a[i];
			cur--;
			i--;
		}
		sol = max(sol, cur);
		cur = n;
		i = 0;
		while(tot % x == 0 && cur > 0){
			tot -= a[i];
			cur--;
			i++;
		}
		sol = max(sol, cur);
		cout << (sol == 0 ? -1 : sol) << '\n';
	}
}
