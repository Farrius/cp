#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		multiset<int> mst;
		set<int> colocar;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mst.insert(a[i]);
			if(a[i] != i) colocar.insert(i);
		}
		vector<int> sol;
		int cnt = 0;
		while(!colocar.empty()){
			int mex;
			for(int i = 0; i <= n; i++){
				if(!mst.count(i)){
					mex = i;
					break;
				}
			}
			if(mex == n){
				int cur = *colocar.begin();
				int val = a[cur];
				a[cur] = n;
				mst.insert(mex);
				mst.erase(mst.lower_bound(val));
				sol.push_back(cur);
			}else{
				int prev = a[mex];
				a[mex] = mex;
				colocar.erase(mex);
				mst.insert(mex);
				mst.erase(mst.lower_bound(prev));
				sol.push_back(mex);
			}
			cnt++;
		}
		cout << cnt << '\n';
		for(int i = 0; i < cnt; i++){
			cout << sol[i] + 1 << (i == cnt - 1 ? '\n' : ' ');
		}
	}
}
