#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

void solve(int t){
  string a, b;cin >> a >> b;
  int z = 0;
  string c ="";
  for (int i = 0; i < b.size(); i++) {
    if (c==a) continue;

    if (a[z] == b[i]) {
      c += b[i];
      z++;
    }
  }
  cout << "Case #" << t << ": ";
  if (a == c) cout << b.size() - c.size() << '\n';
  else cout << "IMPOSSIBLE\n";
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) solve(i);
  return 0;
}
