#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n, k, inp;
bool stop = false;
vector<int> pw(19);
vector<bool> vis;

void qry (int x) {
	if (x >= n || vis[x]) return;
	vis[x] = true;
	cout << x << '\n';
	//cout.flush() << x << '\n';
	cin >> inp;
	if (inp == 1) stop = true;
}

void fn (int i, int x) {
	if (stop) return;
	if (x >= n || i < 0) return;
	x += pw[i];
	qry(x);
	fn(i - 1, x);
	qry(x);
	fn(i - 1, x);
}

int main () {
	pw[0] = 1;
	for (int i = 1; i <= 18; i++) {
		pw[i] = pw[i - 1] * 2;
	}
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		stop = false;
		vis = vector<bool>(n);

		int in = lower_bound(pw.begin(), pw.end(), n - 1) - pw.begin();
		fn(pw[in], 0);
	}
}
