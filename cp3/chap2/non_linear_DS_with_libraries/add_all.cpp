#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	while(cin >> n){
		if(n == 0) break;
		priority_queue<int> pq;
		for(int i = 0; i < n; i++){
			int cur;
			cin >> cur;
			pq.push(-cur);
		}
		ll cost = 0;
		while(pq.size() > 1){
			if(set == 1){
				cost += -pq.top();
				break;
			}
			int cur = -pq.top();
			pq.pop();
			cur += -pq.top();
			pq.pop();
			cost += cur;
			pq.push(-cur);
		}
		cout << cost << '\n';
	}
}
