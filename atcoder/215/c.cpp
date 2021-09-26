#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    string s;
    int k;
    cin >> s >> k;
    sort(s.begin(), s.end());

    int cnt = 0;
    do {
        cnt++;
        if (cnt == k) break;
    } while (next_permutation(s.begin(), s.end()));
    cout << s << '\n';
}
