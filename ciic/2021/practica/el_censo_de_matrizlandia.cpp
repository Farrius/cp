#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;	
	vector<int> tots;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			tots.push_back(x);
		}
	}
	sort(tots.begin(), tots.end());
	k--;
	cout << tots[k] << '\n';
}
