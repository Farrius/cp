#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q;
	cin >> n >> q;
	int ar[n];
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	
	sort(ar, ar + n);

	while(q--){
		int a, b;
		cin >> a >> b;
		int i1 = 0;
		for (int i = n; i >= 1; i /= 2) {
			while(i + i1 < n && ar[i + i1] <= a) i1 += i;
		}
		int i2 = 0;

		for (int i = n; i >= 1; i /= 2) {
			while(i + i2 < n && ar[i + i2] <= b) i2 += i;
		}

		if(ar[i1] < a) i1++;

		cout << i2 - i1 + 1 << '\n';
	}
}
