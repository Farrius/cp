#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void quick_sort(vector<int> &p, vector<int> &c){
	int n = p.size();
	vector<int> cnt(n);
	for(int i = 0; i < n; i++){
		cnt[c[i]]++;
	}
	vector<int> pos(n);
	for(int i = 1; i < n; i++){
		pos[i] = pos[i - 1] + cnt[i - 1];
	}
	vector<int> new_p(n);
	for(auto x: p){
	 	int i = c[x];
		new_p[pos[i]] = x;
		pos[i]++;
	}
	p = new_p;
}
int main(){
	string s;
	cin >> s;
	s += "$";
	int n = s.size();
	vector<int> p(n), c(n);
	vector<pair<char, int>> a(n);
	for(int i = 0; i < n; i++){
		a[i] = {s[i], i};
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++) p[i] = a[i].second;
	for(int i = 1; i < n; i++){
		if(a[i].first == a[i - 1].first) c[p[i]] = c[p[i - 1]];
		else c[p[i]] = c[p[i - 1]] + 1;
	}
	int k = 0;
	while((1<<k) < n){
		for(int i = 0; i < n; i++){
			p[i] = (p[i] - (1<<k) + n) % n;
		}
		quick_sort(p, c);
		vector<int> new_c(n);
		for(int i = 1; i < n; i++){
			pair<int, int> now, prev;
			now = {c[p[i]], c[(p[i] + (1<<k)) % n]};
			prev = {c[p[i - 1]], c[(p[i - 1] + (1<<k)) % n]};
			if(now == prev) new_c[p[i]] = new_c[p[i - 1]];
			else new_c[p[i]] = new_c[p[i - 1]] + 1;
		}
		c = new_c;
		k++;
	}
	for(int i = 0; i < n; i++) cout << p[i] << (i == n - 1 ? '\n' : ' ');
	vector<int> lcp(n);
	k = 0;
	for(int i = 0; i < n - 1; i++){
		int pi = c[i];
		int j = p[pi - 1];
		while(s[i + k] == s[j + k]) k++;
		lcp[pi] = k;
		k = max(k - 1, 0);
	}
	for(int i = 1; i < n; i++) cout << lcp[i] << (i == n - 1 ? '\n' : ' ');
}
