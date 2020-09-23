#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main () {
	ll n;
	cin >> n;
	int sol = 0;

	for (ll i = 2; i * i <= n; i++) {
		if (n % i) continue;
		int cur = 0;

		while (n % i == 0) {
			cur++;
			n /= i;
		}

		for (int j = 1; j <= cur; j++) {
			cur -= j;
			sol++;
		}

	}

	sol += (n > 1);

	cout << sol << '\n';
}
