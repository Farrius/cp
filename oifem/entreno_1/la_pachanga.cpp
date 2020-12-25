#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<pair<int, int>> g[MX];
bool vis[MX], team[MX], ok;
int n, m, mx_h;

//mirar si es bipartite
void dfs (int v, bool equipo) {
    vis[v] = true;
    team[v] = equipo;
    for (auto u : g[v]) {
	if (u.second > mx_h) {
        	if (vis[u.first]) {
            		if (!equipo != team[u.first]) ok = false;
        	} else {
               		dfs(u.first, !equipo);
        	}
	}
    }
}
//checkear si el bs ok
bool check (int mid) {
    //set the variables
    memset(vis, false, sizeof(vis));
    memset(team, false, sizeof(team));
    mx_h = mid;
    ok = true;
    for (int i = 0; i < n && ok; i++) {
        if (vis[i]) continue;
        dfs(i, false);
    }
    return ok;
}

int main () {
    int t;
    cin >> t;
    while (t--) {
        //pillar el input
        cin >> n >> m;    
        for (int i = 0; i < n; i++) {
            g[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
	    g[u].push_back(make_pair(v, w));
	    g[v].push_back(make_pair(u, w));
        }
        //binary search and check parity
        int lo = 0, hi = 1e9;
        int sol = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (check(mid)) {
                sol = min(sol, mid);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << sol << '\n';
    }
}

