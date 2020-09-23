#include <bits/stdc++.h>

using namespace std;

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	vector<int> usb, ps;

	for (int i = 0; i < n; i++) {
		int x;
		string cur;
		cin >> x >> cur;
		if (cur == "USB") {
			usb.push_back(x);
		} else {
			ps.push_back(x);
		}
	}

	sort (usb.begin(), usb.end());
	sort (ps.begin(), ps.end());

	int iUS = 0, iPS = 0;
	long long sol = 0, num = 0;

	for (; iUS < (int) usb.size() && iUS < a; iUS++) {
		sol += usb[iUS];
		num++;
	}

	for (; iPS < (int) ps.size() && iPS < b; iPS++) {
		sol += ps[iPS];
		num++;
	}

	vector<int> quedan;

	for (int i = iUS; i < (int) usb.size(); i++) quedan.push_back(usb[i]);
	for (int i = iPS; i < (int) ps.size(); i++) quedan.push_back(ps[i]);

	sort (quedan.begin(), quedan.end());

	for (int i = 0; i < (int) quedan.size() && i < c; i++) {
		sol += quedan[i];
		num++;
	}

	cout << num << ' ' << sol << '\n';
}
