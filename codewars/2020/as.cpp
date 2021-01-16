#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int z = 1;
	int days = 0;
	while (n > 0) {
		n -= z * 2;
		int c = z;
		z -= (z + 3)/4;
		z += c * 2;
		days++;
	}
	cout << days << " days " << '\n';
}
