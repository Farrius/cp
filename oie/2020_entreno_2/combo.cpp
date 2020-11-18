#include <bits/stdc++.h>

using namespace std;

string guess_sequence(int n) {
	string s;
	string ar = "ABXY";
	vector<bool> ok(4, true);
	string p = "AB";
	int c = press(p);
	if (c == 0) {
		p = "X";
		c = press(p);
		if (c == 0) {
			s = "Y";
			ok[3] = false;
		} else {
			s = "X";
			ok[2] = false;
		}
	} else {
		p = "A";
		c = press(p);
		if (c == 0) {
			s = "B";
			ok[1] = false;
		} else {
			s = "A";
			ok[0] = false;
		}
	}
	//special case
	if (n == 1) return s;
	for (int i = 1; i < n - 1; i++) {
		string u, dos, tres;
		for (int k = 0; k < 4; k++) {
			if (!ok[k]) continue;
			if(!u.size()) u = ar[k];
			else if (!dos.size()) dos = ar[k];
			else tres = ar[k];
		}
		p = s + u + u + s + u + dos + s + u + tres + s + dos;
		c = press(p);
		c -= (int) s.size();
		if (c == 0) {
			s += tres;
		} else if (c == 1) {
			s += dos;
		} else {
			s += u;
		}
	}
	string u, dos, tres;
	for (int k = 0; k < 4; k++) {
		if (!ok[k]) continue;
		if(!u.size()) u = ar[k];
		else if (!dos.size()) dos = ar[k];
		else tres = ar[k];
	}
	p = s + u + s + dos;
	c = press(p);
	c -= (int) s.size();
	if (c == 0) {
		s += tres;
	} else {
		p = s + u;
		c = press(p);
		c -= (int) s.size();
		if (c == 0) {
			s += dos;
		} else {
			s += u;
		}
	}
	return s;
}



