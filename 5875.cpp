#include <iostream>
#include <memory.h>
#include <cmath>
using namespace std;
typedef long long ll;


void solve(){
  string str; cin >> str;
  int state = 0, N = str.size();
  int ans = 0, l = 0;
  for (int i = 1; i <= N; i++) {
    if (str[i-1] == '(') {
      ans += state;
      state = 0;
      l++;
    } else {
      state++;
    }
  }
  cout << ans;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
