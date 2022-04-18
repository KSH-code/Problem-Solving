#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

void solve(){
  int x,y,p1,p2; cin >> x>>y>>p1>>p2;

  for (int i = max(p1,p2); i <= p1*p2*x*y; i++) {
    if ((i-p1)%x + (i-p2)%y ==0) {
      cout << i;
      return;
    }
  }
  cout << -1;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
