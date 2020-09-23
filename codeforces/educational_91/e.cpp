#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m;
	cin >> n >> m;
	vector<set<int>> a(m);
	vector<int> seq(n);
	int ans = n - 1;
	for(int i = 0; i < n; i++){
		cin >> seq[i];
		seq[i]--;
		a[seq[i]].insert(i);
		if(i > 0 && seq[i] == seq[i - 1]) ans--;
	}

	auto merge_into = [&](int desde, int hacia){
		if(a[desde].size() > a[hacia].size()){
			swap(a[desde], a[hacia]);
		}

		for(auto x: a[desde]){
			ans -= a[hacia].count(x + 1);
			ans -= a[hacia].count(x - 1);
		}

		for(auto x: a[desde]){
			a[hacia].insert(x);
		}

		a[desde].clear();
	};

	cout << ans << '\n';
	for(int i = 0; i < m - 1; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		merge_into(v, u);
		cout << ans << '\n';
	}
}
