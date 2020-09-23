#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	vector<string> suf(n);
	string cur = "";
	for(int i = n - 1; i >= 0; i--){
		cur = s[i] + cur;
		suf[i] = cur;
	}
	int q;
	cin >> q;
	while(q--){
		string cur;
		cin >> cur;
		int sol = 0, n_cur = cur.size();
		for(int i = 0 ; i < n; i++){
			if(suf[i].substr(0, n_cur) == cur) sol++;
		}
		cout << sol << '\n';
	}
}
