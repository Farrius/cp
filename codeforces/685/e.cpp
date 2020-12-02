#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int x1, x2, x3, x4, x5, x6;
	cout << "XOR 1 2" << '\n';
	cout.flush();
	cin >> x1;
	cout << "AND 1 2" << '\n';
	cout.flush();
	cin >> x2;
	cout << "XOR 1 3" << '\n';
	cout.flush();
	cin >> x3;
	cout << "AND 1 3" << '\n';
	cout.flush();
	cin >> x4;
	x5 = x1 ^ x3;
	cout << "AND 2 3" << '\n';
	cout.flush();
	cin >> x6;
	int a_b = x1 + x2 * 2;
	int a_c = x3 + x4 * 2;
	int c_b = x5 + x6 * 2;
	int sol[n];
	sol[0] = (a_b + a_c - c_b)/2;
	sol[1] = a_b - sol[0];
	sol[2] = a_c - sol[0];
	for (int i = 3; i < n; i++) {
		int x;
		cout << "XOR 1 " << i + 1 << '\n';
		cout.flush();
		cin >> x;
		sol[i] = x ^ sol[0];
	}
	cout << "! ";
	cout.flush();
	for (int i = 0; i < n; i++) {
		cout << sol[i] << (i == n - 1 ? '\n' : ' ');
		cout.flush();
	}
}
