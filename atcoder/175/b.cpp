#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	int sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if (ar[i] == ar[j] || ar[i] == ar[k] || ar[j] == ar[k]) continue;
				int ai = ar[i], aj = ar[j], ak = ar[k];
				if (ai < aj) swap(ai, aj);
				if (ai < ak) swap(ai, ak);
				if (ai < aj + ak) sol++;
			}
		}
	}
	cout << sol << '\n';
}
