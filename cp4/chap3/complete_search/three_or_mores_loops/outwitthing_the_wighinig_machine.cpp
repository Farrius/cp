#include <bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int n = 10;
		int ar[n], ans[5], cnt[1000], cur[1000];
		memset(cnt, 0, sizeof(cnt));
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> ar[i];
			cnt[ar[i]]++;
			tot += ar[i];
		}
		bool ok = true;
		for (int x = 1; x < tot/5 && ok; x++) {
			for (int i = 0; i < n && ok; i++) {
				for (int j = i + 1; j < n && ok; j++) {
					for (int k = j + 1; j < n && ok; j++) {
						for (int u = k + 1; u < n && ok; u++) {
							int y = ar[i] - x;
							int z = ar[j] - x;
							int l = ar[k] - x;
							int m = ar[u] - x;
							memset(cur, 0, sizeof(cur));
							cur[x + y]++;
							cur[x + z]++;
							cur[x + l]++;
							cur[x + m]++;
							cur[y + z]++;
							cur[y + l]++;
							cur[y + m]++;
							cur[z + l]++;
							cur[z + m]++;
							cur[l + m]++;
							if (cnt[ar[0]] != cur[ar[0]]) continue;
							if (cnt[ar[1]] != cur[ar[1]]) continue;
							if (cnt[ar[2]] != cur[ar[2]]) continue;
							if (cnt[ar[3]] != cur[ar[3]]) continue;
							if (cnt[ar[4]] != cur[ar[4]]) continue;
							if (cnt[ar[5]] != cur[ar[5]]) continue;
							if (cnt[ar[6]] != cur[ar[6]]) continue;
							if (cnt[ar[7]] != cur[ar[7]]) continue;
							if (cnt[ar[8]] != cur[ar[8]]) continue;
							if (cnt[ar[9]] != cur[ar[9]]) continue;
							ok = false;
							if (x > y) swap(x, y);
							if (y > z) swap(z, y);
							if (z > l) swap(l, z);
							cout << "Case " << test << ": " << x << ' ' << y << ' ' << z << ' ' << l << ' ' << m << '\n';
						}
					}
				}
			}
		}
	}
}
