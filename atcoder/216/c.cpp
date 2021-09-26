#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<char> sol;

void fn (ll n) {
    if (n == 0) return;
    fn(n/2);
    if (n/2 > 0) sol.push_back('B');
    if (n % 2) sol.push_back('A');
}

int main () {
    ll n;
    cin >> n;
    fn(n);
    cout << (int) sol.size() << '\n';
    for (auto c : sol) cout << c;
    cout << '\n';
}
