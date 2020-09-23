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
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		int sol = 0, group = 0;
		for(int i = n - 1; i >= 0; i--){
			group++;
			if(a[i] * 1LL * group >= x){
				sol++;
				group = 0;
			}
		}
		cout << sol << '\n';
	}
}
