#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
    ll n;
    cin >> n;
    ll cur = 0;
    while ((1LL<<cur) < n) cur++;
    if ((1LL<<cur) > n) cur--;
    cout << cur << '\n';
}
