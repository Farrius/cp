#include <bits/stdc++.h>

using namespace std;

int main () {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);

	int n;
	cin >> n;
	set<int> bessie;

	for (int i = 1; i <= 2 * n; i++) {
		bessie.insert(i);
	}
	set<int> prev, next;

	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;

		if (i < n/2) prev.insert(cur);
		else next.insert(cur);

		bessie.erase(cur);
	}
	
	int sol = 0;
	set<int>::reverse_iterator itEls = prev.rbegin();
	set<int>::reverse_iterator itBess = bessie.rbegin();
	int i = 0;
	while (i < n/2) {
		if (*itEls < *itBess) {
			sol++;
			itBess++;
		}
		itEls++;
		i++;
	}
	i = 0;
	set<int> bessieLow;
	for (auto x: bessie) {
		if (i < n/2) bessieLow.insert(x);
		else break;
	}

	for (auto x: next) {
		int cur = *bessieLow.begin();
		if (cur < x) {
			sol++;
			bessieLow.erase(cur);
		}
	}

	cout << sol << '\n';
}
