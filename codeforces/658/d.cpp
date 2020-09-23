#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		set<int> puede;
		int a[n * 2];

		for(int i = 0; i < n * 2; i++){
			cin >> a[i];
			puede.insert(a[i]);
		}

		vector<int> sub_sets = {-1};
		
		for(int i = n * 2 - 1; i >= 0; i--){
			int obj = *puede.rbegin();
			int cur = 1;
			while(a[i] != obj){
				puede.erase(a[i]);
				i--;
				cur++;
			}
			puede.erase(obj);
			sub_sets.push_back(cur);
		}

		int dp[sub_sets.size()][n + 1];

		memset(dp, 0, sizeof(dp));

		dp[0][0] = 1;

		for(int i = 1; i < sub_sets.size(); i++){
			for(int cur_n = 0; cur_n <= n; cur_n++){
				dp[i][cur_n] = dp[i - 1][cur_n];
				if(sub_sets[i] <= cur_n){
					dp[i][cur_n] |= dp[i - 1][cur_n - sub_sets[i]];
				}
			}
		}
		
		cout << (dp[sub_sets.size() - 1][n] ? "YES" : "NO") << '\n';
	}
}
