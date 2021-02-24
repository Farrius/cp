#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;


int fn (int l, int r) {
	if (l >= r) return -1;
	cout.flush() << "? " << l << ' ' << r << '\n';
	int bst;
	cin >> bst;
	return bst;
}

int main () {
	int n;
	cin >> n;
	int l = 1, r = n;
	int cur = fn(l, r);
	if (fn(l, cur) != cur) {
	       	l = cur;
		while (r - l > 1) {
			int mid = l + (r - l)/2;
			if (fn(cur, mid) == cur) {
				r = mid;
			} else {
				l = mid;
			}
		}
		cout.flush() << "! " << r << '\n';
	} else {
		r = cur;
		while (r - l > 1) {
			int mid = l + (r - l)/2;
			if (fn(mid, cur) == cur) {
				l = mid;
			} else {
				r = mid;
			}
		}
		cout.flush() << "! " << l << '\n';
	}
}
