#include <iostream>
#include <string>
typedef long long ll;
using namespace std;
void solve(){
  int N; cin >> N;
  deque<pair<ll,ll>> dq;
  for (int i = 0; i < N; i++) {
    ll a; cin >> a;
    if (a == 1) {
      ll b, c; cin >> b >> c;
      dq.push_back({b,c});
    } else {
      ll b; cin >> b;
      ll sum = 0;
      while (b > 0) {
        auto [a,count] = dq.front(); dq.pop_front();
        if (b < count) {
          sum += a * b;
          dq.push_front({a,count-b});
          b = 0;
        } else {
          sum += a * count;
          b -= count;
        }
      }
      cout << result << '\n';
    }
  }
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
