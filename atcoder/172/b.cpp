#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	string s, t;
	cin >> s >> t;
	int dif = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != t[i]) dif++;
	}
	cout << dif << '\n';
}
