#include <bits/stdc++.h>

using namespace std;

void Solve () {
	set<int> ass, loc, weap;
	for (int i = 1; i <= 10; i++) {
		if (i <= 6) {
			ass.insert(i);
			weap.insert(i);
		}
		loc.insert(i);
	}
	int res = -1;
	while (res != 0) {
		int u = *ass.begin(), dos = *loc.begin(), tres = *weap.begin();
		res = Theory(u, dos, tres);
		if (res == 1) {
			ass.erase(ass.begin());
		} else if (res == 2) {
			loc.erase(loc.begin());
		} else if (res == 3) {
			weap.erase(weap.begin());
		}
	}
	return;
}
