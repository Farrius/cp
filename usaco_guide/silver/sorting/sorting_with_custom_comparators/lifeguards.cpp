#include <bits/stdc++.h>

using namespace std;

struct Time {
	int l, r;
};

bool cmp (const Time& a, const Time& b) {
	return a.l < b.l;
}

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int n;
	cin >> n;
	vector<Time> ar(n);
	
	for (int i = 0; i < n; i++) {
		cin >> ar[i].l >> ar[i].r;
	}

	sort(ar.begin(), ar.end(), cmp);
	int tot = 0, iz = 0, der = 0;
	
	for (int i = 0; i < n; i++) {
		if (ar[i].r > der) {
			iz = max(der, ar[i].l);
			tot += ar[i].r - iz;
			der = ar[i].r;
		}
	}

	int res = tot;
	Time last;
	last.l = ar[n - 1].r;
	ar.push_back(last);
	der = 0;
	for (int i = 0; i < n; i++) {
		int curRes = min(ar[i + 1].l, ar[i].r) - max(ar[i].l, der);
		res = min(res, curRes);
		der = max(der, ar[i].r);
	}

	res = max(res, 0);

	cout << tot - res << '\n';
}
