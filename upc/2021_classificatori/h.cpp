#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<string> sol(21);
	sol[0] = "1/1";
	sol[1] = "1/1";
	sol[2] = "1/1";
	sol[3] = "1/1";
	sol[4] = "5/8";
	sol[5] = "31/120";
	sol[6] = "7/90";
	sol[7] = "23/1260";
	sol[8] = "47/13440";
	sol[9] = "41/72576";
	sol[10] = "143/1814400";
	sol[11] = "193/19958400";
	sol[12] = "169/159667200";
	sol[13] = "31/296524800";
	sol[14] = "41/4358914560";
	sol[15] = "127/163459296000";
	sol[16] = "1241/20922789888000";
	sol[17] = "499/118562476032000";
	sol[18] = "893/3201186852864000";
	sol[19] = "211/12164510040883200";
	sol[20] = "353/347557429739520000";
	int n;
	while (cin >> n) {
		cout << sol[n] << '\n';
	}
}
