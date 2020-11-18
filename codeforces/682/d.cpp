#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
using namespace std;
using ll = long long;
using ld = long double;

map<int, int> mpp;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	if (n % 2 == 0) {
		int tot = 0;
		for (int i = 0; i < n; i++) {
			tot ^= ar[i];
		}
		if (tot != 0) {
			cout << "NO" << '\n';
			exit(0);
		}
		n--;
	}
	cout << "YES" << '\n';
	cout << n - 1 << '\n';
	for (int i = 0; i < n/2; i++) {
		cout << i * 2 + 1 << ' ' << i * 2 + 2 << ' ' << n << '\n';
	}
	for (int i = 0; i < n/2; i++) {
		cout << i * 2 + 1 << ' ' << i * 2 + 2 << ' ' << n << '\n';
	}
}
