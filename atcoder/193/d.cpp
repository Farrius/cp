#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int k;
	cin >> k;
	vector<ld> ar(10, k), tk(10), ak(10);
	string s;
	string t;
	cin >> s >> t;
	for (int i = 0; i < 4; i++) {
		ar[s[i] - '0']--;
		ar[t[i] - '0']--;
		tk[s[i] - '0']++;
		ak[t[i] - '0']++;
	}
	ld wins = 0, games = 0;
	for (int i = 1; i <= 9; i++) {
		if (ar[i] == 0) continue;
		ar[i]--;
		tk[i]++;
		for (int j = 1; j <= 9; j++) {
			if (ar[j] == 0) continue;
			ar[j]--;
			ak[j]++;
			ll tak = 0, aok = 0;
			for (int z = 1; z <= 9; z++) {
				tak += z * pow(10, tk[z]);
				aok += z * pow(10, ak[z]);
			}
			ld cur = 0;
			if (i == j) {
				cur = (ar[i] + 2) * (ar[j] + 1);
			} else {
				cur = (ar[i] + 1) * (ar[j] + 1);
			}
			games += cur;
			if (tak > aok) wins += cur;
			ar[j]++;
			ak[j]--;
		}
		ar[i]++;
		tk[i]--;
	}
	cout << fixed << setprecision(10) << wins/games << '\n';
}
