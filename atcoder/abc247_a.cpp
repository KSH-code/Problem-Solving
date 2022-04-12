#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
typedef long long ll;
using namespace std;
void solve(){
  string str; cin >> str;
  string ans = "0";
  for (int i = 0; i < 3; i++) {
    ans += str[i];
  }
  cout << ans;
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
