#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<int, pair<int, int>> mp;
		int sol = 0, cnt = 0, start = 0;
		vector<int> tmp;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			cnt++;
			if(mp[cur].second == 1){
				cnt -= mp[cur].first - start + 1;
				for(int j = start; j <= mp[cur].first; j++){
					mp[tmp[j]].second = 0;
				}
				start = mp[cur].first + 1;
			}
			tmp.push_back(cur);
			sol = max(sol, cnt);
			mp[cur].second++;
			mp[cur].first = i;
		}
		cout << sol << '\n';
	}
}
