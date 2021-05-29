    #include <bits/stdc++.h>
     
    using namespace std;
    using ll = long long;
    using ld = long double;
     
    struct DSU {
        vector<int> e;
        void init (int n) {
            e = vector<int>(n, -1);
        }
        int get (int x) { return e[x] < 0 ? x : e[x] = get(e[x]);}
        int size (int x) {return -e[get(x)];}
        bool unite (int x, int y) {
            x = get(x), y = get(y);
            if (x == y) return false;
            if (e[x] > e[y]) swap(x, y);
            e[x] += e[y];
            e[y] = x;
            return true;
        }
    };
     
    int main () {
        int n, m;
        cin >> n >> m;
        DSU ds;
        ds.init(n);
        while (m--) {
            int t;
            cin >> t;
            vector<int> cur(t);
            for (int i = 0; i < t; i++) {
                cin >> cur[i];
                cur[i]--;
            }
            for (int i = 1; i < t; i++) {
                ds.unite(cur[i], cur[i - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ds.size(i) << (i == n - 1 ? '\n' : ' ');
        }
    }
