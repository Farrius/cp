    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main () {
    	int n;
    	cin >> n;
    	int ar[n];
    	for (int i = 0; i < n; i++) {
    		cin >> ar[i];
    	}
    	vector<int> dp(n);
    	dp[1] = abs(ar[1] - ar[0]);
    	for (int i = 2; i < n; i++) {
    		dp[i] = min(dp[i - 2] + abs(ar[i] - ar[i - 2]), dp[i - 1] + abs(ar[i] - ar[i - 1]));
    	}
    	cout << dp[n - 1] << '\n';
    }
