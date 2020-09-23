#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

	int k, n;
	cin >> k >> n;
	while(n--){
		int x;
		cin >> x;
		int k1 = k;
		int velo = 0;
		int sol = 0;
		while(velo < x && k1 > 0){
			sol++;
			velo++;
			k1 -= velo;
		}
		if(k1 <= 0){
			cout << sol << '\n';
			continue;
		}
		int bajar = x;
		while(k1 > 0){
			if(velo + 1 + bajar <= k1){
				sol++;
				velo++;
				k1 -= velo;
				bajar += velo;
			}else{
				if(velo + bajar <= k1){
					sol++;
					k1 -= velo;
				}else{
					bajar -= vel;
					velo--;
				}
			}
		}
		cout << sol << '\n';
	}
}
