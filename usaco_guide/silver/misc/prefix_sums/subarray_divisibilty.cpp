#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;

	long long sol = 0;
	long long tot = 0;

	map<int, int> mp;
	mp[0]++;

	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		tot += cur;
		tot = ((tot % n) + n) % n;
		sol += mp[tot];
		mp[tot]++;
	}

	cout << sol << '\n';
}
