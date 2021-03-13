#include <bits/stdc++.h>

using namespace std;

int main () {
    int n, x;
	cin >> n >> x;
	int price[n], pages[n];
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> pages[i];
	}
	
	vector<int> dp(x + 1);
	
	for (int i = 0; i < n; i++) {
		for (int c = x; c >= price[i]; c--) {
			dp[c] = max (dp[c], dp[c - price[i]] + pages[i]);
            
		}
	}
	
	cout << dp[x] << '\n';
}
