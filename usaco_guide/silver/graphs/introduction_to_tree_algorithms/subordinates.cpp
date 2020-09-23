#include <bits/stdc++.h>

using namespace std;

const int MX = 2e5 + 5;

vector<int> children[MX];
int subtreeSize[MX], depth[MX];

void dfs (int v) {
	subtreeSize[v] = 1;

	for (auto child : children[v]) {
		depth[child] = depth[v] + 1;
		dfs (child);
		subtreeSize[v] += subtreeSize[child];
	}
}

int main () {
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int parent;
		cin >> parent;
		parent--;
		children[parent].push_back(i);
	}
	
	dfs(0);

	for (int i = 0; i < n; i++) {
		cout << subtreeSize[i] - 1 << (i == n - 1 ? '\n' : ' ');
	}

}

