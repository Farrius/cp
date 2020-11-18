#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 5e18;

vector<ll> lis;

void add (ll x) {
	int lo = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
	if (lo == (int) lis.size()) lis.push_back(x);
	else lis[lo] = x;
}

int main () {
	int n, m;
	cin >> n >> m;
	ll ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	
	for (int i = 0; i < n; i++) {
		ar[i] = m * (i + 1) - ar[i];
	}

	for (ll x: ar) {
		if (x >= 0) add(x);
	}
	
	cout << (n - (int) lis.size()) << '\n';
}
