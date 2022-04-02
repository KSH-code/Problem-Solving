#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

void solve(){
  double x,y;
  cin>>x>>y;
  double s = sqrt(x*x+y*y);
  printf("%.12f %.12f",x/s,y/s);
}

int main(){
  solve();
  return 0;
}
