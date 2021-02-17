#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int lo = 0, hi = n;
	while (hi - lo > 1) {
		int mid = lo + (hi - lo)/2;
		int x1, x2;
		cout.flush() << '?' << ' ' << mid << '\n';
		cin >> x1;
		cout.flush() << '?' << ' ' << mid + 1 << '\n';
		cin >> x2;
		if (x1 < x2) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << '!' << ' ' << hi << '\n';
}	
