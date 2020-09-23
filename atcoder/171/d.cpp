#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	map<int, int> mp;
	ll suma = 0;
	for(int i = 0; i < n; i++){
		int cur;
		cin >> cur;
		mp[cur]++;
		suma += cur;
	}
	int q;
	cin >> q;
	while(q--){
		ll b, c;
		cin >> b >> c;
		ll antes_b = mp[b];
		mp[b] = 0;
		mp[c] += antes_b;
		suma -= antes_b * b;
		suma += antes_b * c;
		cout << suma << '\n';
	}
}
