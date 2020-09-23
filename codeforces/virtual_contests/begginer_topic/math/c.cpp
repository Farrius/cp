#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	ll sol = 0;
	for(int i = 1; i < n; i++){
		sol += (n - i) * i;
	}
	sol += n;
	cout << sol << '\n';
}
