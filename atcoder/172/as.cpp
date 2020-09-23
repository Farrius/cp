#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	int sol = n;
	sol += pow(n, 2);
	sol += pow(n, 3);
	cout << sol << '\n';
}
