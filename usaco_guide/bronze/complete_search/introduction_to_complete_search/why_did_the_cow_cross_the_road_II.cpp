#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	string s;
	cin >> s;
	int n = (int)s.size();
	int sol = 0;
	set<char> visto;
	for(int i = 0; i < n; i++){
		if(visto.count(s[i])) continue;
		visto.insert(s[i]);
		map<int, int> mp;
		mp[s[i]] = 2;
		for(int j = i + 1; ; j++){
			if(s[j] == s[i]) break;
			if(visto.count(s[j])) continue;
			mp[s[j]]++;
		}
		for(auto x: mp){
			if(x.second == 1){
				sol++;
			}
		}
	}

	cout << sol << '\n';
}
