#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll arr[20];

ll check(int length, int width, int height) {
  if (!length || !width || !height) return 0;

  for (int i = 19; i>=0; i--) {
    int t = 1<<i;
    if (arr[i] && length >= t && width >= t && height >= t) {
      arr[i]--;
      ll result = 1;

      result += check(t, t, height-t);

      result += check(length-t, t, height);
      result += check(length, width-t, height);
      return result;
    }
  }
  return -1e9;
}

void solve(){
  ll l,w,h; cin >> l >> w >> h;
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    ll a,b; cin >> a >> b;
    arr[a]+=b;
  }
  cout << max(-1LL, check(l,w,h));
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
