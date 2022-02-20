#include <iostream>
using namespace std;
typedef long long ll;

void solve(){
  double N, D;
  cin >> N >> D;
  ll count = 0;
  for (int i = 0; i < N; i++) {
    double a,b,c;
    cin >> a >> b >> c;
    count += a * b / c >= D;
  }
  cout << count << "\n";
}
int main (){
  int T;cin >>T;while(T--) solve();
}
