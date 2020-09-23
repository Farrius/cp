#include <bits/stdc++.h>

using namespace std;

long long n, k1, m;

bool ok (long long x) {
	long long g = 0, k = k1;
	while(k > 0 && g < n) {
		long long y = (n - g) / x;
		if(y < m) {
      			long long leftover = (n-g + m-1) / m;
      			return leftover <= k;
    		}
    		long long maxmatch = n - (x * y) - g;
    		long long numdays = (maxmatch/y) + 1;
    		if(numdays > k) numdays = k;
    		g += y * numdays;
    		k -= numdays;
  	}
  return g >= n;
}

int main () {
	//freopen("loan.in", "r", stdin);
	//freopen("loan.out", "w", stdout);

	cin >> n >> k1 >> m;

	long long lo = 1, hi = 1e12;
	long long sol = 0;

	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;

		if (ok(mid)) {
			sol = max(sol, mid);
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	cout << sol << '\n';
}
