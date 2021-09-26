#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> z_fn (string s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[z[i] + i]) z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size();
        int fijo = 0;
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r]) {
            l++;
            r--;
            fijo++;
        }
        string ss = s.substr(fijo, n - fijo * 2);
        string sr = ss;
        reverse(sr.begin(), sr.end());
        int m = (int) ss.size();
        if (m == 0) {
            cout << s << '\n';
            continue;
        }
        //prefix
        string pref;
        string st = ss + "#" + sr;
        vector<int> z = z_fn(st);
        for (int i = 0; i < m; i++) {
            if (z[i + m + 1] == m - i) {
                pref = st.substr(i + m + 1, z[i + m + 1]);
                break;
            }
        }
        //cout << pref << " prefijo" << '\n';
        //sufix
        string suf;
        st = sr + "#" + ss;
        z = z_fn(st);
        for (int i = 0; i < m; i++) {
            if (z[i + m + 1] == m - i) {
                suf = st.substr(i + m + 1, z[i + m + 1]);
                break;
            }
        }
        //cout << suf << " sufijo " << '\n';
        //hacer cout
        string pali;
        if ((int) suf.size() > pref.size()) pali = suf;
        else pali = pref;
        
        for (int i = 0; i < fijo; i++) cout << s[i];
        for (int i = 0; i < (int) pali.size()/2; i++) cout << pali[i];
        for (int i = (int) pali.size()/2; i < (int) pali.size(); i++) cout << pali[i];
        for (int i = n - fijo; i < n; i++) cout << s[i];
        cout << '\n';
    }
}
