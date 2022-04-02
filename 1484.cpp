#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
void solve(){
  ll N; cin >> N;
  set<ll> s;
  bool f = false;
  for (ll i = 1; i <= N; i++) {
    s.insert(i*i);
    if (s.count(i*i-N)) {
      cout << i << '\n';
      f = true;
    }
  }
  if (!f) cout << -1;
}
int main()
{
  solve();
  return 0;
}
