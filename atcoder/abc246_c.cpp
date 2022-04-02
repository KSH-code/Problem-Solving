#include <iostream>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

void solve(){
  ll N, K, X; cin >> N >> K >> X;
  ll result = 0;
  priority_queue<ll> pq;
  for(ll i = 0; i < N; i++) {
    ll a; cin >> a;
    pq.push(a);
  }
  while (pq.size()) {
    ll x = pq.top();pq.pop();
    if (K) {
      ll k = min(K, x/X > 0 ? x/X : 1);
      K -=k;
      ll nx = x - k*X;
      if (nx > 0) pq.push(nx);
    } else {
      result += x;
    }
  }
  cout << result;
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
