#include <bits/stdc++.h>

using namespace std;

void f () {
	cout << "error!" << '\n';
}

int main () {
	multiset<int> gu;
	ios_base::sync_with_stdio(0); cin.tie(0);
	char c;
	while (cin >> c) {
		int x;
		if (c == 'S' || c == 'I' || c == 'D') cin >> x;
		if (c == 'S') {
			gu.insert(x);
		} else if (c == 'R') {
			if (gu.empty()) {
				f();
			} else {
				gu.erase(gu.find(*gu.rbegin()));
			}
		} else if (c == 'I') {
			if (gu.empty()) {
				f();
			} else {
				int y = *gu.rbegin();
				gu.erase(gu.find(*gu.rbegin()));
				gu.insert(y + x);
			}
		} else if (c == 'D') {
			if (gu.empty()) {
				f();
			} else {
				int y = *gu.rbegin();
				gu.erase(gu.find(*gu.rbegin()));
				gu.insert(y - x);
			}
		} else if (c == 'A') {
			if (gu.empty()) {
				f();
			} else {
				cout << *gu.rbegin() << '\n';
			}
		}
	}
}
