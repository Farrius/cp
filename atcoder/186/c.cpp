#include <bits/stdc++.h>

using namespace std;

bool fn (int n) {
	int k = n;
	while (k) {
		if (k % 10 == 7) return true;
		k /= 10;
	}
	k = n;
	while (k) {
		if (k % 8 == 7) return true;
		k /= 8;
	}
	return false;
}

int main () {
	int n;
	cin >> n;
	int sol = 0;
	for (int i = 1; i <= n; i++) {
		if (fn(i)) sol++;
	} 
	cout << n - sol << '\n';
}
