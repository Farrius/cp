#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
const int MX = 1e6 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) - 1);

int main () {
	int n;
	cin >> n;
	int ar[n], cnt[MX];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		cnt[ar[i]]++;
	}
	bool full_coprime = true;
	for (int i = 2; i < MX; i++) {
		int cur = 0;
		for (int j = i; j < MX; j += i) {
			cur += cnt[j];
		}
		if (cur > 1) full_coprime = false;
	}
	if (full_coprime) {
		cout << "pairwise coprime" << '\n';
		return 0;
	}
	int common = 0;
	for (int i = 0; i < n; i++) {
		common = __gcd(common, ar[i]);
	}
	if (common == 1) {
		cout << "setwise coprime" << '\n';
	} else {
		cout << "not coprime" << '\n';
	}
}
