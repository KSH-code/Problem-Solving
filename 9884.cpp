#include <iostream>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
}
void solve(){
  int a,b;cin>>a>>b;
  cout << gcd(a,b);
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
