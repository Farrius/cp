#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	int n;
	cin >> n;
	vector<int> ar(n);

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i] *= 2;
	}

	sort (ar.begin(), ar.end());
	int lo = 1, hi = 1e9;
	int sol = hi;

	while (lo <= hi) {
		int mid = lo + (hi - lo)/2;
		int radio = mid;
		int l = ar[0];
		int lB = ar[0], rB = ar[n - 1];
		while (lB <= rB) {
			int start = lB + (rB - lB)/2;
			int posL = start;
			int curL = 1;
			radio = mid;
			while (curL > 0) {
				curL = lower_bound(ar.begin(), ar.end(), posL - radio - 1) - ar.begin();
				if (curL == n) curL--;

				if (ar[curL] < posL - radio && curL < n) curL++;

				if (((posL != start) &&  posL == ar[curL]) || posL < ar[curL] || ar[curL] < posL - radio) {
					break;
				}

				posL = ar[curL];
				radio -= 2;
			}
			if (posL <= ar[0]) {
				l = max(l, start);
				lB = start + 1;
			} else {
				rB = start - 1;
			}
		}
		int curR = -1;
		radio = mid;

		while (curR < n) {
			curR = lower_bound(ar.begin(), ar.end(), l + radio) - ar.begin();

			if (curR == n) {
				l = ar[n - 1];
				break;
			}
			if (curR != 0 && ar[curR] > l + radio) curR--;

			if (((radio != mid) &&  l == ar[curR]) || l > ar[curR] || ar[curR] > l + radio) {
				break;
			}	
			l = ar[curR];
			radio -= 2;
		}

		if (l >= ar[n - 1]) {
			sol = min(sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	
	cout << fixed << setprecision(1) << (double) sol/2.0 << '\n';
}






