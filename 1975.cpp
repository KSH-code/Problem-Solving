#include <iostream>
using namespace std;

void solve(){
  int a; cin >> a;
  int r = 0;
  for (int i = 2; i <=a; i++) {
    int t= a;
    while (t>0&&t%i==0) {
      t/=i;r++;
    }
  }
  cout << r;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while(T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
