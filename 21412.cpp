#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

void solve(){
  int n; cin >> n;
  for (int i = n/2; i >= 1; i--) {
    if (gcd(i, n-i)==1) {
      cout << i << ' ' << n-i;
      return;
    }
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
