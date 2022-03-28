#include <iostream>
using namespace std;
typedef long long ll;

void solve(){
  int a,b; cin >> a>>b;
  while (a!=b) {
    if (a > b) a/=2;
    else b/=2;
  }
  cout << a*10;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int T;cin>>T;while(T--) {
    solve();
    cout <<'\n';
  }

  return 0;
}
