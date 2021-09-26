#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	while (cin >> n) {
		multiset<int> coge;
		priority_queue<int> pq;
		ll tot = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			pq.push(x);
			int k = (i * 2)/3;
			while ((int) coge.size() < k) {
					int y = pq.top();
					pq.pop();
					tot += y;
					coge.insert(y);
			}
			if (!pq.empty() && !coge.empty()) {
				while (pq.top() > *coge.begin()) {
					int y = pq.top();
					pq.pop();
					tot += y - *coge.begin();
					pq.push(*coge.begin());
					coge.erase(coge.begin());
					coge.insert(y);
				}
			}
			cout << tot << '\n';
		}
		cout << "----------" << '\n';
	}
}
