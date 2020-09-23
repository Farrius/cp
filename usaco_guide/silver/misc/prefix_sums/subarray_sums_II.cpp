#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, x;
	cin >> n >> x;
	map<long long, int> mp;
	long long tot = 0;
	mp[0]++;
	long long sol  = 0;
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		tot += cur;
		sol += mp[tot - x];
		mp[tot]++;
	}

	cout << sol << '\n';
}
