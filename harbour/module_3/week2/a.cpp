#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	vector<int> lis;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int in = upper_bound(lis.begin(), lis.end(), x - 1) - lis.begin();
		if (in == (int) lis.size()) lis.push_back(x);
		else lis[in] = x;
	}
	cout << (int) lis.size() << '\n';
}
