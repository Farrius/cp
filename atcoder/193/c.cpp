#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ll n;
	cin >> n;
	set<ll> st;
	for (ll i = 2; i * i <= n; i++) {
		ll k = i;
		while (n/k >= i) {
			k *= i;
			st.insert(k);
		}
	}
	cout << n - (int) st.size() << '\n';
}
