#include <bits/stdc++.h>

using namespace std;

const string base = "abacaba";

int puede(const string& cur){
	int sol = 0;
	for(int i = 0; i < cur.size(); i++){
		if(cur.substr(i, base.size()) == base) sol++;
	}
	return sol;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool res = false;
		for(int i = 0; i + base.size() <= n; i++){
			string ss = s;
			bool hay = true;
			for(int j = 0; j < base.size(); j++){
				if(ss[i + j] != base[j] && ss[i + j] != '?'){
					hay = false;
					break;
				}
				ss[i + j] = base[j];
			}
			if(hay && puede(ss) == 1){
				for(int j = 0; j < n; j++){
					if(ss[j] == '?') ss[j] = 'z';
				}
				cout << "Yes" << '\n';
				cout << ss << '\n';
				res = true;
				break;
			}
		}

		if(!res) cout << "No" << '\n';
	}
}
