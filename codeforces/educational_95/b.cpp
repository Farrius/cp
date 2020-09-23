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
		int ar[n], block[n];
		vector<int> order;
 
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
		}
 
		for (int i = 0; i < n; i++) {
			cin >> block[i];
			if (!block[i]) {
				order.push_back(ar[i]);
			}
		}
 
		sort (order.begin(), order.end(), greater<int>());
		int j = 0;
 
		for (int i = 0; i < n; i++) {
			if (block[i]) {
				cout << ar[i] << (i == n - 1 ? '\n' : ' ');
			} else {
				cout << order[j] << (i == n - 1 ? '\n' : ' ');
				j++;
			}
		}
 
	}
}

