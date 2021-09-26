#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

const ll MX = 1e5 + 5;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> primes;
    vector<bool> sieve(MX);
    for (int i = 2; i < MX; i++) {
        if (sieve[i]) continue;
        primes.push_back(i);
        for (ll j = i * 1LL * i; j < MX; j += i) {
            sieve[j] = true;
        }
    }
    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int>>> tengo(n), busco(n);
    map<vector<pair<int, int>>, int> cuenta;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int div : primes) {
            if (div > x) break;
            if (x % div) continue;
            int cnt = 0;
            while (x % div == 0) {
                x /= div;
                cnt++;
            }
            cnt %= k;
            if (cnt > 0) {
                tengo[i].push_back({div, cnt});
                busco[i].push_back({div, k - cnt});
            }
        }
        cuenta[tengo[i]]++;
    }

    ll sol = 0;
    for (int i = 0; i < n; i++) {
        cuenta[tengo[i]]--;
        sol += cuenta[busco[i]];
    }
    cout << sol << '\n';
}
