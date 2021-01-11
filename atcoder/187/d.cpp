    #include <bits/stdc++.h>
     
    using namespace std;
    using ll = long long;
    using ld = long double;
     
    int main () {
    	int n;
    	cin >> n;
    	ll ar[n], br[n];
	int ind[n];
    	ll ao = 0, tak = 0;
    	for (int i = 0; i < n; i++) {
    		cin >> br[i] >> ar[i];
    		ao += br[i];
    		ind[i] = i;
    	}
    	sort(ind, ind + n, [&] (int a, int b) {
    		return ar[a] + br[a] * 2 > ar[b] + br[b] * 2;
    	});
    	int i = 0;
    	while (i < n && tak <= ao) {
    		ao -= br[ind[i]];
    		tak += br[ind[i]] + ar[ind[i]];
    		i++;
    	}
    	cout << i << '\n';
    }
