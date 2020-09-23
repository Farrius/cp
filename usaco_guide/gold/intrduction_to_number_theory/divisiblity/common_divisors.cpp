#include <bits/stdc++.h>

using namespace std;

int cnt[1000001];

int main () {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j * j <= x; j++) {
			if (x % j) continue;
			cnt[j]++;
			if (j != x/j) cnt[x/j]++;
		}
	}

	for (int i = 1000000; i >= 1; i--) {
		if (cnt[i] >= 2) {
			cout << i << '\n';
			break;
		}
	}
}
