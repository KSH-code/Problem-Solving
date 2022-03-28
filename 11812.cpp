#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;


void solve(){
  ll N,M,K; cin >> N >> M >> K;
  for (int i = 0; i <K; i++) {
    int c = 0;
    ll a, b; cin >> a >> b;
    if (M==1) {
      cout << abs(a-b) << '\n';
      continue;
    }
    while (a != b) {
      if (a > b) {
        a = (a+M-2)/M;
        c++;
      } else {
        b = (b+M-2)/M;
        c++;
      }
    }
    cout << c<<'\n';
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();

  return 0;
}
