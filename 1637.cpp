#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

struct Node {
  ll a,b,c;
};

Node arr[20000];
ll N;
ll result = 0;
bool ok(ll m) {
  ll count = 0;
  for (int i = 0; i < N; i++) {
    auto [a,b,c] = arr[i];
    if (a > m) continue;
    count += (min(b,m)-a)/c+1;
  }
  if (count & 1) return true;

  return false;
}

void solve(){
  cin >> N;
  for (int i = 0; i< N;i++) cin >>arr[i].a>>arr[i].b>>arr[i].c;

  ll l = 0, r = 21474836470;
  while(l+1<r){
    ll m=(l+r)/2;
    if (ok(m)) r = m;
    else l = m;
  }

  for (int i = 0; i < N; i++) {
    auto [a,b,c] = arr[i];
    if (a <= r && b >= r && (r - a) % c == 0) result++;
  }
  if (result % 2) cout << r << ' ' << result;
  else cout << "NOTHING";
}

int main()
{
  cin.tie(0) -> sync_with_stdio(0);
  solve();
  return 0;
}
