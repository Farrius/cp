#include <bits/stdc++.h>

using namespace std;

const int MX = 1e5 + 5;

int ar[MX], x[MX], y[MX];

bool cmp (const int& a, const int& b) {
	if (x[a] == x[b]) return y[a] < y[b];
	else return x[a] < x[b];
}

int main () {
	freopen("moop.in", "r", stdin);
	freopen("moop.out", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		ar[i] = i;
	}

	sort (ar, ar + n, cmp);

	vector<int> lowL(n), maxR(n);
	
	lowL[0] = y[ar[0]];

	for (int i = 1; i < n; i++) {
		lowL[i] = min (lowL[i - 1], y[ar[i]]);
	}

	maxR[n - 1] = y[ar[n - 1]];

	for (int i = n - 2; i >= 0; i--) {
		maxR[i] = max (maxR[i + 1], y[ar[i]]);
	}

	int sol = 1;

	for (int i = 0; i < n - 1; i++) {
		if (lowL[i] > maxR[i + 1]) sol++;
	}

	cout << sol << '\n';
}
