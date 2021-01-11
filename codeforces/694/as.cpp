    #include <bits/stdc++.h>
     
    using namespace std;
    using ll = long long;
    using ld = long double;
     
    int main () {
    	int t;
    	cin >> t;
    	while (t--) {
    		int n, x;
    		cin >> n >> x;
    		int ar[n];
    		ll tot = 0;
    		for (int i = 0; i < n; i++) {
    			cin >> ar[i];
    			tot += ar[i];
    		}
    		cout << (tot + x - 1)/x << ' ';
    		tot = 0;
    		for (int i = 0; i < n; i++) {
    			tot += (ar[i] + x - 1)/x;
    		}
    		cout << tot << '\n';
    	}
    }
