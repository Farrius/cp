#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n;
	cin >> n;
	string sol = "";
	while(n){
		n--;
		char cur = (n % 26) + 'a';
		sol = cur + sol;
		n /= 26;
	}
	cout << sol << '\n';
}
