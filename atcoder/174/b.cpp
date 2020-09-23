#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main() {
	ld n, d;
	cin >> n >> d;
	int sol = 0;
	while(n--) {
		ld x, y;
		cin >> x >> y;
		ld dist = sqrt(x * x + y * y);
		if(dist <= d) sol++;
	}

	cout << sol << '\n';
}
