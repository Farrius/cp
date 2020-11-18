#include <bits/stdc++.h>
#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()	
using namespace std;
using ll = long long;
using ld = long double;

ll power (ll n, ll k) {
	ll res = 1;
	while (k) {
		if (k % 2) res *= n;
		n *= n;
		k /= 2;
	}
	return res;
}

int main () {
	 ll n;
	 cin >> n;
	 if (n % 2) cout << 0 << '\n';
	 else cout << power(2LL, n/2) << '\n';
}
