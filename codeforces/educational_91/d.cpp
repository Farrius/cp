#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 2e5 + 1;

int a[maxN], b[maxN];
int n, m;
ll x, k, y;

bool upd(int l, int r, ll &res){
	if(l > r) return true;
	bool puededel = false;

	int mx = *max_element(a + l, a + r + 1);
	int len = r - l + 1;

	if(l - 1 >= 0 && a[l - 1] > mx) puededel = true;
	if(r + 1 < n && a[r + 1] > mx) puededel = true;
	if(len < k && !puededel) return false;

	int need = len % k;
	res += need * y;
	len -= need;
	if(y * k >= x){
		res += len/k * x;
	}else if(puededel){
		res += len * y;
	}else{
		res += (len - k) * y + x;
	}

	return true;
}
int main(){
	cin >> n >> m;
	cin >> x >> k >> y;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];

	ll res = 0;
	int lst = -1, posa = 0, posb = 0;

	while(posb < m){
		while(posa < n && a[posa] != b[posb]) posa++;
		if(posa == n){
			cout << -1 << '\n';
			return 0;
		}

		if(!upd(lst + 1, posa - 1, res)){
			cout << -1 << '\n';
			return 0;
		}

		lst = posa;
		posb++;
	}

	if(!upd(lst + 1, n - 1, res)){
		cout << -1 << '\n';
		return 0;
	}

	cout << res << '\n';
}


