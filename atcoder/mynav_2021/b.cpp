#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<pair<int, string>> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i].second >> ar[i].first;
	}
	sort(ar.begin(), ar.end());
	cout << ar[n - 2].second << '\n';
}
