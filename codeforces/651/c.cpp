#include<bits/stdc++.h>
using namespace std;

const int N = 50000;

void player_1(){
		cout << "Ashishgup" << endl;
}

void player_2(){
		cout << "FastestFinger" << endl;
}

bool check_prime(int n){
	for(int i = 2; i < min(n, N); i++)
		if(n % i == 0)
			return 0;
	return 1;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		bool lose = (n == 1);
		if(n > 2 && n % 2 == 0){
			if((n & (n - 1)) == 0)
				lose = 1;
			else if(n % 4 != 0 && check_prime(n / 2))
				lose = 1;
		}
		if(lose)
			player_2();
		else player_1();
	}
}
