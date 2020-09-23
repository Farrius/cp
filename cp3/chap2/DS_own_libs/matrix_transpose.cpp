#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxN = 1e4 + 1;

int matrix[maxN][maxN];

int main(){
	int n, m;
	while(cin >> n >> m){
		memset(matrix, 0, sizeof(matrix));
		int rows = m, cols = n;
		for(int i = 0; i < n; i++){
			int k;
			cin >> k;
			vector<int> posis(k);
			for(int j = 0; j < k; j++){
				int cur;
				cin >> cur;
				cur--;
				posis[j] = cur;
			}
			for(int j = 0; j < k; j++){
				cin >> matrix[posis[j]][i];
			}
		}
		cout << rows << ' ' << cols << '\n';
		for(int i = 0; i < rows; i++){
			int nonzero = 0;
			vector<int> indices, values;
			for(int j = 0; j < cols; j++){
				if(matrix[i][j] == 0) continue;
				nonzero++;
				indices.push_back(j + 1);
				values.push_back(matrix[i][j]);
			}
			if(nonzero == 0){
				cout << '0' << '\n';
				cout << '\n';
			}else{
				cout << nonzero << ' ';
				for(int p = 0; p < indices.size(); p++){
					cout << indices[p] << (p == indices.size() - 1 ? '\n' : ' ');
				}
				for(int p = 0; p < values.size(); p++){
					cout << values[p] << (p == values.size() - 1 ? '\n' : ' ');
				}
			}
		}
	}
}
