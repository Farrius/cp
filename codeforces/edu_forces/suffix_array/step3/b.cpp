#include <bits/stdc++.h>

using namespace std;

void quick_sort(vector<int> &p, vector<int> &c){
	int n = p.size();
	vector<int> cnt(n);
	for(auto x: c){
		cnt[x]++;
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
	for(int i = 0; i < n; i++){
		p[i] = a[i].second;
	}
	c[p[0]] = 0;
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
		new_c[p[0]] = 0;
		for(int i = 1; i < n; i++){
			pair<int, int> now = {c[p[i]], c[(p[i] + (1<<k)) % n]};
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1<<k)) % n]};
			if(now == prev) new_c[p[i]] = new_c[p[i - 1]];
			else new_c[p[i]] = new_c[p[i - 1]] + 1;
		}
		c = new_c;
		k++;
	}
	int q;
	cin >> q;
	while(q--){	
		string cur;
		cin >> cur;
		int n_cur = cur.size(), cuenta = 0;
		int l = 0, r = n - 1;
		int mini = INT_MAX, maxi = INT_MIN;
		bool esta = false;
		while(l <= r){
			int mid = l + (r - l)/2;
			string subs_cur = s.substr(p[mid], n_cur);
			if(subs_cur >= cur){
				if(subs_cur == cur) esta = true;
				mini = min(mini, mid);
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		l = 0, r = n - 1;
		while(l <= r){
			int mid = l + (r - l)/2;
			string subs_cur = s.substr(p[mid], n_cur);
			if(subs_cur <= cur){
				maxi = max(maxi, mid);
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		if(!esta){
			cout << 0 << '\n';
		}else{
			int sol = maxi - mini + 1;
			cout << sol << '\n';
		}
	}
}












