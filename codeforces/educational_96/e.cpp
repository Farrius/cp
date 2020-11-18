#include <bits/stdc++.h>

using namespace std;
	
const int MX = 2e5 + 5;
int indchar[26];
vector<int> poschar[26];
int ar[MX], bit[MX];

int n;

int sum (int i) {
	int suma = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1) {
		suma += bit[i];
	}

	return suma;
}

void update (int i) {
	for (; i < n; i = (i | (i + 1))) {
		bit[i]++;
	}
}

int main () {
	string s;
	cin >> n >> s;
	string base = s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < (int) s.size(); i++) {
		int cur = s[i] - 'a';
		poschar[cur].push_back(i);
	}
	
	for (int i = 0; i < (int) base.size(); i++) {
		int cur = base[i] - 'a';
		ar[i] = poschar[cur][indchar[cur]];
		indchar[cur]++;
	}
	
	long long sol = 0;
	for(int i = n - 1; i >= 0; i--) {
		sol += sum(ar[i]);
		update(ar[i]);
	}
	
	cout << sol << '\n';
}
