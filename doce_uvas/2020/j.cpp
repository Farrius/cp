#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int p, n;
	while (cin >> p >> n) {
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		ll lo = 0, hi = p;
		ll gasto = 0, umbral = 0;
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			ll k = p, cur_gast = 0;
			for (int i = 0; i < n; i++) {
				k -= min(mid, ar[i] * 1LL);
				cur_gast += min(mid, ar[i] * 1LL);
			}
			if (k < 0) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
				gasto = cur_gast;
				umbral = mid;
			}
		}
		ll sol = umbral;
		lo = 0, hi = umbral;
		while (lo <= hi) {
			ll mid = lo + (hi - lo)/2;
			ll cur_gast = 0;
			for (int i = 0; i < n; i++) {
				cur_gast += min(mid, ar[i] * 1LL);
			}
			if (cur_gast < gasto) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
				sol = mid;
			}
		}
		cout << sol << '\n';
	}
}
