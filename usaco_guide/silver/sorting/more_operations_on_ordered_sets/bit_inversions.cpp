#include <bits/stdc++.h>

using namespace std;

set<int> dif;
multiset<int> seqs;
string s;
int n;

void fn (int x) {
	if (x == 0 || x == n) return;
	auto it = dif.find(x);
	if (it == dif.end()) {
		dif.insert(x);
		it = dif.find(x);
		auto a = *prev(it), b = *next(it);
		seqs.erase(seqs.find(b - a));
		seqs.insert(x - a);
		seqs.insert(b - x);
	} else {
		auto a = *prev(it), b = *next(it);
		seqs.erase(seqs.find(x - a));
		seqs.erase(seqs.find(b - x));
		seqs.insert(b - a);	
		dif.erase(x);
	}
}

int main () {
	cin >> s;
	n = (int) s.size();
	dif.insert(0);
	dif.insert(n);
	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[i + 1]) dif.insert(i + 1);
	}
	for (auto it = dif.begin(); next(it) != dif.end(); it++) {
		seqs.insert(*next(it) - *it);	
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		fn(x - 1);
		fn(x);
		cout << *seqs.rbegin() << ' ';
		if (q == 0) cout << '\n';
	}
}
