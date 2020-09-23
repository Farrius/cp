#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;
		int sol = 1;

		for (int i = 2; i * i <= x; i++) {
			if (x % i != 0) continue;
			int cur = 0;

			while (x % i == 0) {
				x /= i;
				cur++;
			}

			sol *= (cur + 1);
		}
		
		if (x > 1) sol *= 2;

		cout << sol << '\n';
	}
}
