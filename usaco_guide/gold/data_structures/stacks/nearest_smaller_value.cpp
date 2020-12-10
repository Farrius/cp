#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	stack<pair<int, int>> vistos;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		while (!vistos.empty() && vistos.top().first >= x) vistos.pop();
		if (vistos.empty()) cout << 0 << ' ';
		else cout << vistos.top().second + 1 << ' ';
		vistos.push(make_pair(x, i));
	}
	cout << '\n';
}
