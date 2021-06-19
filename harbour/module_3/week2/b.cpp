#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	for (int i = 0; i < n; i++) {
		int in = upper_bound(lis.begin(), lis.end(), ar[i] - 1) - lis.begin();
		if (in == (int) lis.size()) lis.push_back(ar[i]);
		else lis[in] = ar[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		int in = upper_bound(lis.begin(), lis.end(), ar[i] - 1) - lis.begin();
		if (in == (int) lis.size()) lis.push_back(ar[i]);
		else lis[in] = ar[i];
	}

	cout << (int) lis.size() << '\n';
}
