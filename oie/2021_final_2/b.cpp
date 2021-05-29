#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int res;

void ask (int x) {
	cout.flush() << "? " << x << '\n';
	cin >> res;
}

int main () {
	int n;
	cin >> n;
	set<int> vist;
	for (int i = 0; i < 1e5; i++) {
		ask(i);
		int cur = 0;
		for (int j = 0; j < 31; j++) {
			if ((res>>j) & 1) {
				if ((i>>j) & 1 == 0) cur += (1<<j);
			} else {
				if ((i>>j) & 1) cur += (1<<j);
			}
		}
		vist.insert(cur);
	}
	cout.flush() << "! ";
	for (auto x : vist) {
		cout << x << ' ';
	}
}
