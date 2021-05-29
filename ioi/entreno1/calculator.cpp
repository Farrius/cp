#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;

int i, m;
string s;

int fn ();

int f () {
	if (s[i] >= '0' && s[i] <= '9') {
		int res = s[i] - '0';
		i++;	
		return res;
	}
	i++;
	int sol = fn();
	i++;
	return sol;
}

int t () {
	int num = f();
	while (i < m && (s[i] == '*' || s[i] == '/')) {
		if (s[i] == '*') {
			i++;
			num *= f();
		} else {
			i++;
			num /= f();
		}
	}
	return  num;
}

int fn () {
	int sol = t();
	while (i < m && (s[i] == '+' || s[i] == '-')) {
		if (s[i] == '+') {
			i++;
			sol += t();
		} else {
			i++;
			sol -= t();
		}
	}
	return sol;
}
 
int main () {
	while (cin >> s) {
		i = 0;
		m = (int) s.size();
		cout << fn() << '\n';
	}
}
