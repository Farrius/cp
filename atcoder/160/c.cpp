#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, k;
	cin >> k >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int maxi = 0, tot = 0;
	for(int i = 0; i < n - 1; i++){
		maxi = max(maxi, a[i + 1] - a[i]);
	}
	maxi = max(maxi, k + a[0] - a[n - 1]);
	cout << k - maxi << '\n';
}
