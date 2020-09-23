#include <bits/stdc++.h>

using namespace std;

int main () {
	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	long long n;
	cin >> n;
	char ar[n];
	vector<long long> masY(n + 1), masX(n + 1), menosY(n + 1), menosX(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	for (int i = 0; i < n; i++) {
		masY[i + 1] += masY[i];
		masX[i + 1] += masX[i];
		menosY[i + 1] += menosY[i];
		menosX[i + 1] += menosX[i];

		if (ar[i] == 'U') masY[i + 1]++;
		else if (ar[i] == 'D') menosY[i + 1]++;
		else if (ar[i] == 'L') menosX[i + 1]++;
		else masX[i + 1]++;
	}

	long long tope = 1e18;
	long long lo = 1, hi = tope - 1;
	long long sol = tope;
	while (lo <= hi) {
		long long mid = lo + (hi - lo)/2;

		long long resto = mid % n;
		long long vuelta = mid/n;
		bool aX = false, aY = false;
		long long tot, quedan = mid;

		auto fn = [&] (long long c1, long long c2, bool& ok, vector<long long>& a, vector<long long>& b) {
			tot = (a[n] - b[n]) *  vuelta;
			tot = tot + a[resto] - b[resto];
			long long dist = abs((c1 + tot) - c2);
			ok = (dist <= quedan);
			quedan -= dist;
		};

		fn(x1, x2, aX, masX, menosX);
		fn(y1, y2, aY, masY, menosY);

		if (aX && aY) {
			sol = min(sol, mid);
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	cout << (sol == tope ? -1 : sol) << '\n';
}
