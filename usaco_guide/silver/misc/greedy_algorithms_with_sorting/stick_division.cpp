#include <bits/stdc++.h>
 
using namespace std;
 
int main () {
	int x, n;
	cin >> x >> n;
 
	priority_queue<int> pq;
 
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		pq.push(-cur);
	}
 
	long long sol = 0;

	while ((int) pq.size() > 1) {
		int c = -pq.top();
		pq.pop();
		c += -pq.top();
		pq.pop();
		sol += c;
		pq.push(-c);
	}
 
	cout << sol << '\n';
}
