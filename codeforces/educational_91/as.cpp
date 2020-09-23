#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		bool ok = false;
		for(int i = 2; i < n; i++){
			if(ok) break;
			if(a[i] < a[i - 1] && a[i - 1] > a[i - 2]){
				cout << "YES" << '\n';
				cout << i - 2 + 1 << ' ' << i - 1 + 1 << ' ' << i + 1 << '\n';
				ok = true;
			}
		}
		if(!ok) cout << "NO" << '\n';
	}
}
