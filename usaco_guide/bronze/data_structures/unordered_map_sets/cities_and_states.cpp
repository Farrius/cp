#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("citystate.in", "r", stdin);
	freopen("citystate.out", "w", stdout);

	int n;
	cin >> n;
	map<string, vector<string>> mp;
	int sol = 0;

	for(int i = 0; i < n; i++){
		string cur, kei2;
		cin >> cur >> kei2;
		string kei1 = cur.substr(0, 2);
		mp[kei2].push_back(kei1);
		int suma = 0;
		for(auto x: mp[kei1]){
			if(x == kei2 && x != kei1) suma++;
		}
		sol += suma;
	}

	cout << sol << '\n';
}
