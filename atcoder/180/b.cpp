#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = 1e9;

int main () {
	int n;
	cin >> n;
	ll man = 0;
	ld euclid = 0;
	int cheb = -INF;
	for (int i = 0; i < n; i++) {
		ld x;
		cin >> x;
		man += abs(x);
		euclid += x * x;
		cheb = max(cheb, abs((int) x));
	}

	cout << man << '\n';
	cout << fixed << setprecision(10) << sqrt(euclid) << '\n';
	cout << cheb << '\n';
}
