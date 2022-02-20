#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  ll x, y;
  cin >> x >> y;
  if (x < 0 && y > 0) cout << '-';
  if (x == 0) {
    cout << 0;
    return 0;
  }

  ll z = y;
  int i = 1;

  vector<ll> result;
  while (x) {
    ll c = 0;
    if (y > 0 && x > 0) {
      result.push_back(x%y);
    } else if ((z > 0) ^ (x < 0)) {
      c = abs(y) - abs(x % y);
      c = abs(x % y) == 0 ? 0 : c;
      result.push_back(c);
    } else {
      result.push_back(x%y);
    }
    if (c) {
      ll xx = x < 0 ? -1 : 1;
      x /= abs(y);
      x += xx;
    } else {
      x /= abs(y);
    }
    z *= y;
    i++;
  }
  reverse(result.begin(), result.end());
  for (auto r : result) cout << abs(r);
  return 0;
}
