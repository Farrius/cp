#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	int n;
	cin >> n;
	cout << (n/2 + 1) * ((n + 1)/2 + 1) * (n % 2 + 1)  << '\n';
}
