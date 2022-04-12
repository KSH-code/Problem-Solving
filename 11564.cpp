#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(){
  ll k,a,b;
  cin>>k>>a>>b;

  ll count = 0;
  if (a <= 0 && b >= 0) {
    count++;
    count += abs(a) / k;
    count += abs(b) / k;
  } else {
    a = abs(a);
    b = abs(b);
    if (a > b) swap(a,b);
    count += b/k;
    count -= a/k;
    if (a % k == 0) count++;
  }
  cout << count;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
