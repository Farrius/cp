#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 2e5 + 2;

ll a[maxN], b[maxN];

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i + 1];
		a[i + 1] += a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i + 1];
		b[i + 1] += b[i];
	}
	int sol = 0;
	for(int i = 0, j = m; i <= n; i++){
		if(a[i] > k) break;
		while(a[i] + b[j] > k) j--;
		sol = max(sol, i + j);
	}
	cout << sol << '\n';
}
