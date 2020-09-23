#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll sol = s.size(), neg = 1, acc = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '+'){
				acc++;
			}else{
				if(acc == 0){
					sol += i + 1;
				}else{
					acc--;
				}
			}
		}
		cout << sol << '\n';
	}
}
