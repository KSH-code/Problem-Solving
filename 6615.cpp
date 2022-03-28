#include <iostream>
#include <map>
using namespace std;
typedef unsigned long long ll;

bool solve(){
  ll a,b; cin >> a>>b;
  ll aa=a,bb=b;
  if (a+b==0) return false;

  map<ll,int>m;
  m[a]=0;
  int i=1;
  while (a!=1) {
    if (a % 2) {
      a = 3*a+1;
    } else {
      a = a/2;
    }
    m[a] = i++;
  }

  i=0;
  while (!m.count(b)) {
    if (b % 2) {
      b = 3*b+1;
    } else {
      b = b/2;
    }
    i++;
  }
  printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n",aa,m[b],bb,i,b);

  return true;
}

int main()
{
  while (solve());

  return 0;
}
