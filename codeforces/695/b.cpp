#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ar[n];
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
		vector<int> vall, hill;
		vector<bool> vall_pos(n), hill_pos(n);
		for (int i = 1; i < n - 1; i++) {
			if (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) {
				hill.push_back(i);
				hill_pos[i] = true;
			}
			if (ar[i] < ar[i - 1] && ar[i] < ar[i + 1]) {
				vall.push_back(i);
				vall_pos[i] = true;
			}
		}
		int quita = 1;
		for (int i = 1; i < n - 1; i++) {
			//rodeado afecta a 3
			if (vall_pos[i] && hill_pos[i + 1] && hill_pos[i - 1]) quita = max(quita, 3);
			if (hill_pos[i] && vall_pos[i + 1] && vall_pos[i - 1]) quita = max(quita, 3);
			//afecta a 2 
			if (hill_pos[i]) {
				//miramos que no se crea un hill
				if (vall_pos[i + 1] && (ar[i - 1] <= ar[i + 1] || ar[i - 1] <= (i - 2 < 0 ? 1e9 : ar[i - 2]))) {
					quita = max(quita, 2);
				} 
				if (vall_pos[i - 1] && (ar[i + 1] <= ar[i - 1] || ar[i + 1] <= (i + 2 == n ? 1e9 : ar[i + 2]))) {
					quita = max(quita, 2);
				}
			}
			if (vall_pos[i]) {
				//miramos que no se crea un vall
				if (hill_pos[i + 1] && (ar[i - 1] >= ar[i + 1] || ar[i - 1] >= (i - 2 < 0 ? 0 : ar[i - 2]))) {
					quita = max(quita, 2);
				} 
				if (hill_pos[i - 1] && (ar[i + 1] >= ar[i - 1] || ar[i + 1] >= (i + 2 == n ? 0 : ar[i + 2]))) {
					quita = max(quita, 2);
				}
			}
		}
		int sol = max(0, (int) vall.size() + (int) hill.size() - quita);
		cout << sol << '\n';
	}
}
