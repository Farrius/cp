#include <bits/stdc++.h>

using namespace std;

using ld = long double;

int main () {
	int n;
	cin >> n;

	ld aS[n], bS[n];

	for (int i = 0; i < n; i++) {
		cin >> aS[i] >> bS[i];
	}
	sort (aS, aS + n, greater<ld>());
	sort (bS, bS + n, greater<ld>());

	vector<ld> prefA(n + 1);

	for (int i = 1; i <= n; i++) {
		prefA[i] = prefA[i - 1] + aS[i - 1] - 1;
	}

	ld sol = 0;
	ld b = 0;
	int mB = 0;

	for (int i = 1; i <= n && mB < n; i++) {
		b--;
		while (mB < n && min(prefA[i] - mB - 1, b + bS[mB] - 1) > min(prefA[i] - mB, b)) {
			b += bS[mB];
			b--;
			mB++;
		}
		sol = max(sol, min(prefA[i] - mB, b));
	}
	cout << fixed << setprecision(4) << sol << '\n';
}
