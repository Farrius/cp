#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	while (cin >> n) {
		int sol = 0;
		int ar[n], br[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> br[i];
		}
		for (int i = 0; i < n; i++) {
			int x = br[i], pos = -1;
			for (int j = i; j < n; j++) {
				if (ar[j] == x) {
					pos = j;
					break;
				}
			}
			while (pos > i) {
				sol++;
				swap(ar[pos], ar[pos - 1]);
				pos--;
			}
		}
		cout << sol << '\n';
	}
}
