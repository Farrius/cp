#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int sol = 0, n, tot;
vector<pair<int, int>> song;

void fn (int i, int w1, int w2, int acc) {
	if (i == n) {
		sol = max(sol, acc);
	} else {
		int cur = acc;
		int queda = w1 + w2;
		for (int j = i; j < n; j++) {
			if (queda < song[j].second) {
				cur += (song[j].first + song[j].second - 1)/song[j].second * queda;
				queda = 0;
				break;
			} else {
				cur += song[j].first;
				queda -= song[j].second;
			}
		}
		if (cur <= sol) return;
		if (song[i].second <= w1) fn(i + 1, w1 - song[i].second, w2, acc + song[i].first);
		if (w1 != w2 && song[i].second <= w2) fn(i + 1, w1, w2 - song[i].second, acc + song[i].first);
		fn(i + 1, w1, w2, acc);
	}
}

bool cmp (pair<int, int> a, pair<int, int> b) {
	return a.first * b.second > b.first * a.second;
}

int main () {
	while (cin >> n) {
		if (n == 0) break;
		cin >> tot;
		song.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> song[i].second >> song[i].first;
		}
		sort(song.begin(), song.end(), cmp);
		sol = 0;
		fn(0, tot, tot, 0);
		cout << sol << '\n';
	}
}
