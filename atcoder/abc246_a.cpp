#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

void solve(){
  int x1,x2,x3,y1,y2,y3;
  map<int,int> x;
  map<int,int> y;
  for (int i = 0; i < 3; i++) {
    int a, b; cin >> a >> b;
    x[a]++;
    y[b]++;
  }
  for (auto [a,b] : x) {
    if (b == 1) cout << a << ' ';
  }
  for (auto [a,b] : y) {
    if (b == 1) cout << a << ' ';
  }
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
