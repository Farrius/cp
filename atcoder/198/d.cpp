#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int n1, n2, n3;
string s1, s2, s3;
bool ok = false;

map<char, int> valor;
ll ten[20];

void fn () {
	if (valor[s1[0]] == 0 || valor[s2[0]] == 0 || valor[s3[0]] == 0) return;
	ll a = 0;
	for (int i = 0; i < n1; i++) {
		a += valor[s1[i]] * 1LL * ten[n1 - i - 1];
	}
	ll b = 0;
	for (int i = 0; i < n2; i++) {
		b += valor[s2[i]] * 1LL * ten[n2 - i - 1];
	}
	ll c = 0;
	for (int i = 0; i < n3; i++) {
		c += valor[s3[i]] * 1LL * ten[n3 - i - 1];
	}
	if (a + b == c) {
		cout << a << '\n';
		cout << b << '\n';
		cout << c << '\n';
		ok = true;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ten[0] = 1;
	for (int i = 1; i <= 15; i++) {
		ten[i] = ten[i - 1] * 10LL;
	}
	cin >> s1 >> s2 >> s3;
	n1 = (int) s1.size(), n2 = (int) s2.size(), n3 = (int) s3.size();
	set<char> hay;
	for (int i = 0; i < n1; i++) {
		hay.insert(s1[i]);
	}
	for (int i = 0; i < n2; i++) {
		hay.insert(s2[i]);
	}
	for (int i = 0; i < n3; i++) {
		hay.insert(s3[i]);
	}
	if ((int) hay.size() > 10) {
		cout << "UNSOLVABLE" << '\n';
		return 0;
	}
	while ((int) hay.size() < 10) {
		for (char c = 'a'; c <= 'z'; c++) {
			if (!hay.count(c)) {
				hay.insert(c);
				break;
			}

		}
	}
	vector<char> ar;
	for (auto x : hay) {
		ar.push_back(x);
	}
	sort(ar.begin(), ar.end());
	
	do {
		for (int i = 0; i < 10; i++) {
			valor[ar[i]] = i;
		}
		fn();
		if (ok) break;
	} while (next_permutation(ar.begin(), ar.end()));
	if (!ok) cout << "UNSOLVABLE" << '\n';
}
