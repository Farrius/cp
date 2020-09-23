#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);

	int n;
	cin >> n;
	
	int lo = 1, hi = 2e9;

	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		
		if (mid - mid/5 - mid/3 + mid/15 < n) {
			lo = mid + 1;
		} else {
			if (mid - mid/5 - mid/3 + mid/15 == n && mid % 3 && mid % 5) {
				cout << mid << '\n';
				return 0;
			}
			hi = mid - 1;
		}
	}
}
