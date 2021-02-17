#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		ar[i]--;
	}
	vector<int> cnt[n];
	for (int i = 0; i < n; i++) {
		cnt[ar[i]].push_back(i);
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		if (cnt[i].empty()) continue;
		sol++;
		int last_i = 1;
		for (int j = 1; j < (int) cnt[i].size(); j++) {
			last_i = max(0, last_i - (cnt[i][j] - cnt[i][j - 1] - 1));
			if (last_i <= 1) {
				last_i++;
				sol++;
			}
		}
	}
	cout << sol << '\n';
}	
