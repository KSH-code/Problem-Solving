#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll c(ll a, ll b) {
  ll count=0;
  for (ll i = b; i <= a; i*=b) count+=a/i;
  return count;
}
int main(){
  ll n,r;cin >>n>>r;
  ll t=c(n,2)-c(r,2)-c(n-r,2);
  ll f=c(n,5)-c(r,5)-c(n-r,5);
  cout << min(t,f);
  return 0;
}
