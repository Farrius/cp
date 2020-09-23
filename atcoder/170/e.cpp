#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 2 * 1e5 + 7;

int main(){
	int n, q;
	cin >> n >> q;
	pair<int, int> info[n];
	vector<multiset<int>> gardens(maxN);
	multiset<int> sol;
	for(int i = 0; i < n; i++){
		int rate, garden;
		cin >> rate >> garden;
		info[i] = make_pair(rate, garden);
		gardens[garden].insert(rate);
	}
	for(auto x: gardens){
		if(!x.empty()) sol.insert(*x.rbegin());
	}
	while(q--){
		int c, d;
		cin >> c >> d;
		c--;
		int garden = info[c].second, rate = info[c].first;
		gardens[garden].erase(gardens[garden].lower_bound(rate));
		if(gardens[garden].empty()){
			sol.erase(sol.lower_bound(rate));
		}else{
			if(*gardens[garden].rbegin() < rate){
				sol.erase(sol.lower_bound(rate));
				sol.insert(*gardens[garden].rbegin());
			}
		}
		info[c].second = d;
		if(gardens[d].empty()){
			sol.insert(rate);
		}else{
			if(*gardens[d].rbegin() < rate){
				sol.erase(sol.lower_bound(*gardens[d].rbegin()));
				sol.insert(rate);
			}
		}
		gardens[d].insert(rate);
		cout << *sol.begin() << '\n';
	}
}
