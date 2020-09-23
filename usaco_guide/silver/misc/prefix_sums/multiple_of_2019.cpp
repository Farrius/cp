#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int ten = 1, sum = 0, cnt[2019] = {};
  long long ans = 0;
  for(int i = 0; i < s.size(); i++){
    cnt[sum]++;
    sum += (s[i] - '0') * ten;
    sum %= 2019;
    ans += cnt[sum];
    ten = (ten * 10) % 2019; 
  }
  cout << ans << endl;
}
