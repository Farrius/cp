#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> flowers(m);

		for(auto &flower: flowers){
			cin >> flower.first >> flower.second;
		}

		sort(flowers.rbegin(), flowers.rend());

		vector<ll> pref_sum(m + 1);

		for(int i = 0; i < m; i++){
			pref_sum[i + 1] = pref_sum[i] + flowers[i].first;
		}

		ll best = 0;

		for(int i = 0; i < m; i++){
			int usar = flowers[i].second;
			ll total = flowers[i].first;
			int hasta = lower_bound(flowers.begin(), flowers.end(), make_pair(usar, -1), greater<pair<int, int>>()) - flowers.begin();
			
			if(hasta > n - (hasta <= i)){
				hasta = n - 1;
			}

			total += pref_sum[hasta] - (hasta > i ? flowers[i].first : 0);
			total += (n - (hasta + (hasta <= i))) * 1LL * usar;
			best = max(best, total);
		}

		cout << best << '\n';
	}
}
