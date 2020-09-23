#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int pos = -1, cnt = 0;
		for(int i = n - 1; i >= 0; i--){
			if(s[i] == '0'){
				pos = i;
				break;
			}
		}
		for(int i = 0; i < n; i++){
			if(i == pos) break;
			if(s[i] == '1') break;
			else cnt++;
		}
		if(pos == -1) pos = 0;
		for(int i = 0; i < cnt; i++){
			cout << '0';
		}
		for(int i = pos; i < n; i++){
			cout << s[i];
		}
		cout << '\n';
	}
}
