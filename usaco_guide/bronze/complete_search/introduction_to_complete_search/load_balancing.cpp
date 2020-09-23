#include <bits/stdc++.h>

using namespace std;


int main(){
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);

	int n, b;
	cin >> n >> b;
	int yS[n], xS[n];
	for(int i = 0; i < n; i++){
		cin >> xS[i] >> yS[i];
	}

	int sol = n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x = xS[i] + 1;
			int y = yS[j] + 1;
			int freq[4] = {0, 0, 0, 0};
			for(int k = 0; k < n; k++){
				if(xS[k] < x && yS[k] > y){
					freq[0]++;
				}else if(xS[k] > x && yS[k] > y){
					freq[1]++;
				}else if(xS[k] < x && yS[k] < y){
					freq[2]++;
				}else{
					freq[3]++;
				}
			}
			int curSol = *max_element(freq, freq + 4);
			sol = min(sol, curSol);
		}
	}

	cout << sol << '\n';
}
