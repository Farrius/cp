#include <bits/stdc++.h>

using namespace std;

const int MX = 2e3 + 5;

int points[MX], pp[MX];

bool cmp (const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	if (a.first == b.first) {
		if (a.second.first == b.second.first) return a.second.second < b.second.second;
		else return a.second.first > b.second.first;
	} else {
		return a.first > b.first;
	}
}

int main () {
	int n, t, p;
	cin >> n >> t >> p;
	vector<pair<int, pair<int, int>>> score;
	vector<vector<int>> ar(n, vector<int>(t));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < t; j++) {
			cin >> ar[i][j];
			if (ar[i][j] == 1) points[j]++;
		}
	}
	for (int i = 0; i < n; i++) {
		int cur = 0, prob = 0;
		for (int j = 0; j < t; j++) {
			if (ar[i][j] == 1) {
				prob++;
				cur += n - points[j];
			}
		}
		score.push_back(make_pair(cur, make_pair(prob, i)));
	}
	sort(score.begin(), score.end(), cmp);
	p--;
	for (int i = 0; i < n; i++) {
		if (score[i].second.second == p) {
			cout << score[i].first << ' ' <<  i + 1 << '\n';
			break;
		}
	}
}
