#include <iostream>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

ll X(ll a, ll b) {
  return a*a*(a+b)+b*b*(a+b);
}

void solve(){
  ll N; cin >> N;
  ll result = -1;
  ll a = 0;
  for (; a <= 1000000; a++) {
    if (a*a*a>=N) break;
  }
  ll lb = 0;
  for (ll i = a; i >= 0; i--) {
    for (ll b = lb; true; b++) {
      ll c = X(i,b);
      if (c>=N) {
        if (result == -1) result = c;
        else result = min(result, c);
        lb = b;
        break;
      }
    }
  }
  cout << result;
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
