#include <bits/stdc++.h>

using namespace std;

int n, fotos = 0;
map<string, int> mp;
int cnt[7];

void fn () {
	if (cnt[0] == 0) return;
	int k = 0;
	for (int i = 0; i < 7; i++) {
		if (cnt[i] > 0) k++;
	}
	if (k >= 3) {
		fotos++;
		for (int i = 0; i < 7; i++) {
			if (cnt[i] > 0) cnt[i]--;
		}
	}
}

int main () {
	mp["Mafalda"] = 0;
	mp["Felipe"] = 1;
	mp["Manolito"] = 2;
	mp["Susanita"] = 3;
	mp["Miguelito"] = 4;
	mp["Libertad"] = 5;
	mp["Guille"] = 6;
	while (cin >> n) {
		if (n == 0) break;
		fotos = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			string x;
			cin >> x;
			cnt[mp[x]]++;
			fn();
		}
		int pringaos = 0;
		for (int i = 0; i < 7; i++) {
			pringaos += cnt[i];
		}
		cout << fotos << ' ' << pringaos << '\n';
	}
}
