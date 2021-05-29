#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	vector<int> cnt(205);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i] = ar[i] % 200;
		cnt[ar[i]]++;
	}
	sort(ar, ar + n);
	ll sol = 0;
	for (auto x : ar) {
		cnt[x]--;
		sol += cnt[x];
	}
	cout << sol << '\n';
}
