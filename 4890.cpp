#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

bool solve(){
  ll a,b; cin >> a>>b;
  if (a+b==0) return false;
  if (a==b) cout << 1;
  else cout << lcm(a,b) / gcd(a,b);
  return true;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  while(solve())cout<<'\n';
  return 0;
}
