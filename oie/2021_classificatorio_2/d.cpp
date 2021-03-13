#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int t = 0, par = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			int x; 
			cin >> x;
			sum += x;
			if (x % 2) t++;
			par += x/2;
		}
		if (t == 0) {
			cout << 1 << '\n';
			continue;
		}
		vector<int> divs = {1};
		for (int i = 2; i * i <= sum; i++) {
			if (sum % i == 0) {
				divs.push_back(i);
				if (i != sum/i) divs.push_back(sum/i);
			}
		}
		sort(divs.begin(), divs.end());
		int sol = sum;
		for (auto x : divs) {
			if (x < t || (x - t) % 2 != 0) continue;
			int npar = par - (x - t)/2;
			if (npar % x == 0) {
				sol = x;
				break;
			}
		
		}
		cout << sol << '\n';
	}
}
