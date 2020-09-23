#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int ar[n];
	int maxi = 0;
	for(int i = 0; i < n; i++){
		int cur;
		cin >> cur;
		maxi ^= cur;
		ar[i] = cur;
	}
	for(int i = 0; i < n; i++){
		int sol = maxi ^ ar[i];
		cout << sol << (i == n - 1 ? '\n' : ' ');
	}
}
