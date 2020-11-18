#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

vector<int> memory(25, -1);
bool ok[25];
int sol = 0;

void play () {
	int cur = 1;
	while (sol < 25) {
		char u = faceup(cur);
		if (memory[u - 'A'] != -1) {
			faceup(memory[u - 'A']);
			cur++;
			if (!ok[u - 'A']) {
				ok[u - 'A'] = true;
				sol++;
			}
		} else {
			memory[u - 'A'] = cur;
			char dos = faceup(cur + 1);
			if (dos == u) {
				if (!ok[u - 'A']) {
					ok[u - 'A'] = true;
					sol++;
				}
			}
			if (memory[dos - 'A'] == -1) {
				memory[dos - 'A'] = cur + 1;
				cur += 2;
			} else {
				cur++;
			}
		}
	}
}
