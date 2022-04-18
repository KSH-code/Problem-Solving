#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

void solve(){
  ll L,N,F,B; cin >> L >> N >> F >> B;
  ll result = 0;

  priority_queue<pair<ll,ll>> pq;
  for (int i = 0; i < N; i++) {
    ll a,b;cin >> a >> b;
    pq.push({b,a});
  }
  ll before = 0;
  while (pq.size()) {
    auto [b,a] = pq.top(); pq.pop();
    if (before > a) continue;
    result += (a - before) * (F - B) * b;
    before = a;
  }
  cout << result;
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
