#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		ll d, k;
		cin >> d >> k;
		d *= d;
		ll cur = 0, a = 0, b = 0;
		ll tot = 0;
		while (cur <= d) {
			if (a > b) swap(a, b);
			a += k;
			cur = a * a + b * b;
			tot++;
		}
		tot--;
		cout << (tot % 2 ? "Ashish" : "Utkarsh") << '\n';
	}
}
