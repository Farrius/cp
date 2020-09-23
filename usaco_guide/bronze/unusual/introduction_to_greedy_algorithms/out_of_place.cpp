#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int sol = 0;
	for(int i = 0; i < n; i++){
		if(b[i] != a[i]) sol++;
	}
	cout << sol - 1 << '\n';
}
