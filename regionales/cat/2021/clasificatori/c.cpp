#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void f () {
	cout << "error: magatzem buit" << '\n';
}

int main () {
	multiset<int> mag;
	char c;
	while (cin >> c) {
		if (c == 'N') {
			if (mag.empty()) {
				f();
			} else {
				cout << *mag.begin() << '\n';
			}
		} else if (c == 'X') {
			if (mag.empty()) {
				f();
			} else {
				cout << *mag.rbegin() << '\n';
			}
		} else if (c == 'A') {
			int x;
			cin >> x;
			mag.insert(x);
		} else {
			int x;
			cin >> x;
			if (!mag.count(x)) {
				cout << "error: preu inexistent (" << x << ")" << '\n';
			} else {
				mag.erase(mag.find(x));
			}
		}
	}
}
