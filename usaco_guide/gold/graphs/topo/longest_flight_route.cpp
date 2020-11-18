#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int MX = 2e5 + 5;

vector<int> g[MX], inverseG[MX], degree(MX), dist(MX, -INF), p(MX, -1);

int n, m;

void fn () {
	queue<int> q;
	for(int i = 0; i < n; i++) {
		if (degree[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int v = q.front();
		q.pop();

        
		for(int u : g[v]) {
			degree[u]--;
			if(degree[u] == 0) q.push(u);
        	}

        	int mxPrev = -1;
        	for(int prev : inverseG[v]) {
            		if(dist[prev] + 1 > dist[v]) {
                		dist[v] = dist[prev] + 1;
				mxPrev = prev;
			}
            	}
		if(v == 0) dist[v] = 1;
        	p[v] = mxPrev;
        }
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		degree[b]++;
		g[a].push_back(b);
		inverseG[b].push_back(a);
	}

	fn();
    
	stack<int> sol;
	int temp = n - 1;
    	bool contains0 = false;
	if(temp == 0) contains0 = true;
	while(temp != -1 && dist[temp] >= 0) {
		sol.push(temp);
		temp = p[temp];
		if(temp == 0) contains0 = true;
    
	}

	if(contains0) {
		cout << dist[n - 1] << '\n';
		while(!sol.empty()) {
			cout << sol.top() + 1;
			sol.pop();
			if(!sol.empty()) cout << " ";
		}
		cout << '\n';
	} else {
        	cout << "IMPOSSIBLE" << '\n';
	}
}
