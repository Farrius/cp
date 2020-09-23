#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxi = 1e6 + 7;
int main(){
	int n;
	cin >> n;
	int ar[n];
	set<int> st;
	map<int, int> mp;
	for(int i = 0; i < n; i++){
		int cur;
		cin >> cur;
		ar[i] = cur;
		st.insert(cur);
		mp[cur]++;
	}
	vector<int> sieve(maxi,1);
	sieve[0] = 0;
	for(int i = 1; i < maxi; i++){
		if(sieve[i] == 0) continue;
		if(st.count(i)){
			for(int j = 2; i * j < maxi; j++){
				sieve[i * j] = 0;
			}
		}
	}
	int cnt = 0;
	for(int x: ar){
		if(sieve[x] == 1 && mp[x] == 1) cnt++;
	}
	cout << cnt << '\n';
}
