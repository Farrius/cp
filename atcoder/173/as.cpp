#include <bits/stdc++.h>

sing namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int res = n % 1000;
	if(res == 0) cout << 0 << '\n';
	else cout << 1000 - res << '\n';
}
