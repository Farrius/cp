#include <bits/stdc++.h>

#define mp make_pair
#define f first
#define s second
#define len(x) (int) x.size()
using namespace std;
using ll = long long;
using ld = long double;

const int MX = 1e5 + 5;
const ll INF = 1e18;

vector<pair<int, int>> g[MX];
priority_queue<ll> best[MX];
int n, m, k;

int main () {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(mp(b, c));
	}
	priority_queue<pair<ll, int>> pq;
	pq.push(mp(0, 0));
	best[0].push(0);
	while (!pq.empty()) {
		ll cur = -pq.top().f;
		int v = pq.top().s;
		pq.pop();
		if (cur > best[v].top()) continue; 
		for (auto u : g[v]) {
			ll nxt = cur + u.s;
			if (len(best[u.f]) < k) {
				best[u.f].push(nxt);
				pq.push(mp(-(nxt), u.f));
			} else if (nxt < best[u.f].top()) {
				best[u.f].pop();
				best[u.f].push(nxt);
				pq.push(mp(-(nxt), u.f));
			}
		}
	}
	vector<ll> sol;
	while (!best[n - 1].empty()) {
		sol.push_back(best[n - 1].top());
		best[n - 1].pop();
	}
	reverse(sol.begin(), sol.end());
	for (int i = 0; i < len(sol); i++) {
		cout << sol[i] << (i == len(sol) - 1 ? '\n' : ' ');
	}
}
