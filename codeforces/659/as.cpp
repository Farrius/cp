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
		cin >> n;
		string s(51, 'a');
		cout << s << '\n';
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			if(s[cur] == 'a') s[cur] = 'b';
			else s[cur] = 'a';
			cout << s << '\n';
		}
	}
}
