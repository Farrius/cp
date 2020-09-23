#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	priority_queue<int> pq;
	for(int i = 0; i < n;i++){
		int cur; 
		cin >> cur;
		pq.push(cur);
	}

	ll sol = 0;
	int cnt = 0;
	cnt = 2;
	sol += pq.top();
	pq.pop();
	int actual = 0;
	while(cnt < n){
		if(actual == 1){
			cnt++;
			sol += pq.top();
			pq.pop();
			actual = 0;
			continue;
		}
		actual++;
		cnt++;
		sol += pq.top();
	}
	cout << sol << '\n';
}
