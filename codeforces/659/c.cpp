#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long ld;

const int MOD = 1e9 + 7;
const int MX = 2e5 + 5;
const ll INF = 1e18;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		string s1, s2;
		cin >> n >> s1 >> s2;
		bool puede = true;
		for(int i = 0; i < n; i++){
			if(s1[i] > s2[i]) puede = false;
		}
		if(!puede){
			cout << -1 << '\n';
			continue;
		}
		set<int> a[26];
		for(int i = 0; i < n; i++){
			if(s1[i] == s2[i]) continue;
			a[s1[i] - 'a'].insert((s2[i] - 'a') - (s1[i] - 'a'));
		}
		int sol = 0;
		for(int i = 0; i < 26; i++){
			if(a[i].empty()) continue;
			sol++;
			int next = *a[i].begin();
			for(auto x: a[i]){
				if(x > next){
					a[i + next].insert(x - next);
				}
			}
		}
		cout << sol << '\n';
	}
}
