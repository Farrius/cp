#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int fn (int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main () {
	int a, b;
	cin >> a >> b;
	cout << max(fn(a), fn(b)) << '\n';
}
