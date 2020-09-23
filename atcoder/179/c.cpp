#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int sol = 0;
	
	for (int a = 1; a < n; a++) {
		sol += (n - 1)/a;		
	}

	cout << sol << '\n';
}
