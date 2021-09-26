#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;

int cnt[2][26];

int main () {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ar[n];
	for (int i = 0; i < n; i++) {
		ar[i] = s[i] - 'a';
	}
	int j = 0;
	int stc = k;
	while (j < n) {
		bool ok = false;
		cnt[j % 2][ar[j]]++;
		if (j % 2 == 0) {
			if (ar[j] == ar[0]) ok = true;
		} else {
			if (ar[j] == ar[1]) ok = true;
		}
		if (ok) {
			j++;
		} else if (stc) {
			j++;
			stc--;
		} else {
			break;
		}
	}
	int sol = j;
	for (int i = 0; i < n - 2; i++) {
		int u = (i + 1) % 2, d = (i + 2) % 2;
		cnt[d][ar[i]]--;
		int par = ar[i + 1];
		int inp = ar[i + 2];
		int queda = 0;
		for (int ii = 0; ii < 26; ii++) {
			queda += cnt[u][ii];
			queda += cnt[d][ii];
			if (par == ii) {
				queda -= cnt[u][ii];
			}
			if (inp == ii) {
				queda -= cnt[d][ii];
			}
		}
		int c = k - queda;
		for (int jj = 0; jj < c && j < n; jj++) {
			cnt[jj % 2][ar[j++]]++;
		}
		sol = max(sol, j - i - 1);
	}
	//reverse
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		ar[i] = s[i] - 'a';
	}
	j = 0;
	stc = k;
	while (j < n) {
		bool ok = false;
		cnt[j % 2][ar[j]]++;
		if (j % 2 == 0) {
			if (ar[j] == ar[0]) ok = true;
		} else {
			if (ar[j] == ar[1]) ok = true;
		}
		if (ok) {
			j++;
		} else if (stc) {
			j++;
			stc--;
		} else {
			break;
		}
	}
	sol = max(sol, j);
	for (int i = 0; i < n - 2; i++) {
		int u = (i + 1) % 2, d = (i + 2) % 2;
		cnt[d][ar[i]]--;
		int par = ar[i + 1];
		int inp = ar[i + 2];
		int queda = 0;
		for (int ii = 0; ii < 26; ii++) {
			queda += cnt[u][ii];
			queda += cnt[d][ii];
			if (par == ii) {
				queda -= cnt[u][ii];
			}
			if (inp == ii) {
				queda -= cnt[d][ii];
			}
		}
		int c = k - queda;
		for (int jj = 0; jj < c && j < n; jj++) {
			cnt[jj % 2][ar[j++]]++;
		}
		sol = max(sol, j - i - 1);
	}
	
	for (int let = 0;
	cout << sol << '\n';
}
