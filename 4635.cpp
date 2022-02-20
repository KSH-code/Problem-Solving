#include <iostream>
using namespace std;
typedef long long ll;

void solve(int N){
  ll prev = 0;
  ll result = 0;
  for (int i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    result += (b - prev) * a;
    prev = b;
  }
  cout << result << " miles\n";
}
int main (){
  int T;while(cin >>T && T > 0) solve(T);
}
