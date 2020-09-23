#include <bits/stdc++.h>

using namespace std;

int main () {
	long long n, x;
	cin >> n >> x;
	pair<long long, int> ar[n];

	for (int i = 0; i < n; i++) {
		cin >> ar[i].first;
		ar[i].second = i + 1;
	}

	sort (ar, ar + n);
	
	for (int i = 0; i < n; i++) {
		long long  cur = x - ar[i].first;
		for (int j = i + 1, k = n - 1; j < k; j++) {
			while (j < k && ar[j].first + ar[k].first > cur) {
				k--;
			}

			if (j < k && ar[j].first + ar[k].first == cur) {
				cout << ar[i].second << ' ' << ar[j].second << ' ' << ar[k].second << '\n';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}
