#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll sol = 0;
	for(int i = 0; i < n; i++){
		sol += (i + 1) * 1LL * (n - i);
	}
	for(int i = 0; i < n - 1; i++){
		int l, r;
		cin >> l >> r;
		int mini = min(l, r);
		int maxi = max(l, r);
		sol -= mini * 1LL * (n - maxi + 1);
	}
	cout << sol <<'\n';
}
