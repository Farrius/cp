#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	while(cin >> n){
		if(n == 0) break;
		multiset<int> mset;
		ll sol = 0;
		while(n--){
			int k;
			cin >> k;
			for(int i = 0; i < k; i++){
				int cur;
				cin >> cur;
				mset.insert(cur);
			}
			int low = *mset.begin();
			int high = *mset.rbegin();
			sol += (high - low);
			mset.erase(mset.lower_bound(low));
			mset.erase(mset.lower_bound(high));
		}
		cout << sol << '\n';
	}
}
