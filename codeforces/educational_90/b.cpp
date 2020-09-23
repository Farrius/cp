#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int unos = 0, zeros = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '1') unos++;
			else zeros++;
		}
		int sol = min(unos, zeros);
		cout << (sol % 2 ? "DA" : "NET") << '\n';
	}
}
