lude <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
		int t;
			cin >> t;
				while(t--){
							int n;
									cin >> n;
											vector<int> pares, inpares;
													for(int i = 1; i <= 2 * n; i++){
																	int cur;
																				cin >> cur;
																							if(cur % 2) inpares.push_back(i);
																										else pares.push_back(i);
																												}
															int cnt = 0;
																	for(int i = 0; i + 2 <= pares.size(); i += 2){
																					if(cnt == n - 1) break;
																								cout << pares[i] << ' ' << pares[i + 1] << '\n';
																											cnt++;
																													}
																			for(int i = 0; i + 2 <= inpares.size(); i += 2){
																							if(cnt == n -1) break;
																										cout << inpares[i] << ' ' << inpares[i + 1] << '\n';
																													cnt++;
																															}
																				}
}#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
		int t;
			cin >> t;
				while(t--){
							int n;
									cin >> n;
											vector<int> pares, inpares;
													for(int i = 1; i <= 2 * n; i++){
																	int cur;
																				cin >> cur;
																							if(cur % 2) inpares.push_back(i);
																										else pares.push_back(i);
																												}
															int cnt = 0;
																	for(int i = 0; i + 2 <= pares.size(); i += 2){
																					if(cnt == n - 1) break;
																								cout << pares[i] << ' ' << pares[i + 1] << '\n';
																											cnt++;
																													}
																			for(int i = 0; i + 2 <= inpares.size(); i += 2){
																							if(cnt == n -1) break;
																										cout << inpares[i] << ' ' << inpares[i + 1] << '\n';
																													cnt++;
																															}
																				}
}#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
		int t;
			cin >> t;
				while(t--){
							int n;
									cin >> n;
											vector<int> pares, inpares;
													for(int i = 1; i <= 2 * n; i++){
																	int cur;
																				cin >> cur;
																							if(cur % 2) inpares.push_back(i);
																										else pares.push_back(i);
																												}
															int cnt = 0;
																	for(int i = 0; i + 2 <= pares.size(); i += 2){
																					if(cnt == n - 1) break;
																								cout << pares[i] << ' ' << pares[i + 1] << '\n';
																											cnt++;
																													}
																			for(int i = 0; i + 2 <= inpares.size(); i += 2){
																							if(cnt == n -1) break;
																										cout << inpares[i] << ' ' << inpares[i + 1] << '\n';
																													cnt++;
																															}
																				}

