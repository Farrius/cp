#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main() {
	int k;
	cin >> k;
	int res = 1;
	int seq = 7 % k;
	while(res <= k) {
		if(seq % k == 0) {
			cout << res << '\n';
			return 0;
		}

		seq = (((seq % k) * (10 % k)) % k) + (7 % k);
		res++;
	}
	cout << -1 << '\n';
}
