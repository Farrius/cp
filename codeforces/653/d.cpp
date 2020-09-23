#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		set<int> quedan;
		map<int, int> freq;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			int res = cur % k;
			if(res != 0){
				quedan.insert(k - res);
				freq[k - res]++;
			}
		}
		ll sol = 0;
		if(!quedan.empty()) sol++;
		while(!quedan.empty()){
			int despues = k - *quedan.rbegin();
			sol += *quedan.rbegin();
			for(auto x: freq){
				freq[x.first]--;
				if(freq[x.first] == 0) quedan.erase(x.first);
			}
			if(!quedan.empty()){
				sol += despues;
			}
		}
		cout << sol << '\n';
	}
}
