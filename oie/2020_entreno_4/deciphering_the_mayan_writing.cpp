#include <bits/stdc++.h>

using namespace std;

int fn (char c) {
	if (c > 'Z') {
		return (c - 'a') + 26;
	} else {
		return c - 'A';
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int g, s;
	cin >> g >> s;
	vector<int> cnt(52), me_cnt(52);
	string w, ss;
	cin >> w >> ss;
	for (int i = 0; i < g; i++) {
		int cur = fn(w[i]);
		cnt[cur]++;
	}
	int sol = 0;
	for (int i = 0; i < s; i++) {
		int letter = fn(ss[i]);
		if (i >= g) {
			me_cnt[fn(ss[i - g])]--;
		}
		me_cnt[letter]++;
		bool ok = true;
		for (int j = 0; j < 52; j++) {
			if (me_cnt[j] != cnt[j]) ok = false;
		}
		if (ok) sol++;
	}
	cout << sol << '\n';
}
