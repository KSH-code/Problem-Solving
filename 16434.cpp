#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Node {
  ll a,b,c;
};

ll N,M;
Node arr[123456];
bool ok(ll m) {
  ll cur_hp = m;
  ll cur_damage = M;
  for (int i = 0; i < N; i++) {
    auto [a,b,c] = arr[i];
    if (a == 1) {
      cur_hp -= b * (c / cur_damage - (c % cur_damage == 0));
      if (cur_hp <= 0) return false;
    } else {
      cur_damage += b;
      cur_hp = min(m, cur_hp+c);
    }
  }
  return true;
}
void solve(){
  cin >> N >> M;
  for (int i = 0; i< N;i++) cin >> arr[i].a >> arr[i].b >> arr[i].c;
  ll l=0,r=1e17;
  while(l+1<r){
    ll m=(l+r)/2;
    if (!ok(m)) l = m;
    else r = m;
  }
  cout << r;
}

int main()
{
  cin.tie(0) -> sync_with_stdio(0);
  solve();
  return 0;
}
