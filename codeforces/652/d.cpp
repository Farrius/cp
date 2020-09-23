#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 2 * 1e6;
const int MOD = 1e9 + 7;

int dp[maxN];

int main(){
	dp[0] = dp[1] = 0;
	dp[2] = 4;
	for(int i = 3; i < maxN; i++){
		ll cur = dp[i - 1];
		cur +=  2 * dp[i - 2] + (i % 3 == 2)*4;
		cur %= MOD;
		dp[i] = cur;
	}
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n--;
		cout << dp[n] << '\n';
	}
}
