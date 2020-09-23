#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	string s;
	int n, p, k;
	priority_queue<pair<int, int>> pq;
	map<int, int> mp;
	while(cin >> s){
		if(s == "#") break;
		cin >> n >> p;
		mp[n] = p;
		pq.push({-p, -n});
	}
	cin >> k;
	while(k--){
		int cur = pq.top().second;
		cout << -cur << '\n';
		int value = pq.top().first;
		value -= mp[-cur];
		pq.pop();
		pq.push({value, cur});
	}
}
