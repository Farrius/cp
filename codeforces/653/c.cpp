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
		int sol = 0, acc = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == ')'){
				if(acc > 0){
					acc--;
				}else{
					sol++;
				}
			}else{
				acc++;
			}
		}
		cout << sol << '\n';
	}
}
