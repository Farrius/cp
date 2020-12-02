#include <bits/stdc++.h>

using namespace std;

int n, p[128];

void write (int a, int b, string s) {
	if (a == b) return;
	int mid = (a + b)/2;
	for (int i = a; i <= mid ; i++) {
		s[i] = '1';
		add_element(s);
		s[i] = '0';
	}
	string ns = string(n, '1');
	for (int i = a; i <= mid; i++) {
		ns[i] = '0';
	}
	write(a, mid, ns);
	ns = string(n, '1');
	for (int i = mid + 1; i <= b; i++) {
		ns[i] = '0';
	}
	write(mid + 1, b, ns);
}

void read (int a, int b, string s) {
	if (a == b) {
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') p[i] = a;
		}
	} else {
		string ns = string(n, '1');
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				s[i] = '1';
				if (check_element(s)) ns[i] = '0';
				s[i] = '0';
			}
		}
		int mid = (a + b)/2;
		read(a, mid, ns);
		for (int i = 0; i < n; i++) {
			if (ns[i] == '0') {
				ns[i] = '1';
			} else {
				if (s[i] == '0') ns[i] = '0';
			}
		}
		read(mid + 1, b, ns);
	}
}

int* restore_permutation (int m, int w, int r) {
	n = m;
	write(0, n - 1, string(n, '0'));
	compile_set();
	read(0, n - 1, string(n, '0'));
	return p;
}
