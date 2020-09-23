#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	cin >> t;
	while(t--){
		set<char> st;
		string s;
		int edges = 0;
		while(cin >> s){
			if(s[0] == '*') break;
			st.insert(s[1]);
			st.insert(s[3]);
			edges++;
		}
		string vertex;
		cin >> vertex;
		int acorns = 0, v = 0;
		for(int i = 0; i < vertex.size(); i++){
			if(vertex[i] == ',') continue;
			if(!st.count(vertex[i])) acorns++;
			v++;
		}
		cout << "There are " << v - acorns - edges << " tree(s) and " << acorns << " acorn(s)." << '\n';
	}
}
