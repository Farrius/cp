#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	while(cin >> n){
		stack<int> stck;
		queue<int> q;
		priority_queue<int> pq;
		bool a = true, b = true, c = true;
		while(n--){
			int order, val;
			cin >> order >> val;
			if(order == 1){
				stck.push(val);
				q.push(val);
				pq.push(val);
			}else{
				if(stck.empty() || stck.top() != val) a = false;
				if(q.empty() || q.front() != val) b = false;
				if(pq.empty() || pq.top() != val) c = false;
				if(!stck.empty()) stck.pop();
				if(!q.empty()) q.pop();
				if(!pq.empty()) pq.pop();
			}
		}
		if(a || b || c){
			if((a && b) || (b && c) || (a && c)){
				cout << "not sure" << '\n';
			}else{
				if(a) cout << "stack" << '\n';
				else if(b) cout << "queue" << '\n';
				else cout << "priority queue" << '\n';
			}
		}else{
			cout << "impossible" << '\n';
		}
	}
}
