#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		for (int i = 0; i < n; i++) {
			cout << 'a';
		}
		cout << '\n';
		return 0;
	}
	string bona;
	for (int i = 0; i < k; i++) {
		for (int j = i; j < k - 1; j++) {
			bona += (char) ('a' + j);
			bona += (char) ('a' + i);
		}
		bona += (char) ('a' + (k - 1));
	}
	int largo = (int) bona.size();
	int veces = n/largo, res = n % largo;
	for (int i = 0; i < veces; i++) {
		cout << bona;
	}
	for (int i = 0; i < res; i++) {
		cout << bona[i];
	}
	cout << '\n';
}
