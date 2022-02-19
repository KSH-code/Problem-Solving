#include <iostream>
#include <list>
#include <string>
using namespace std;

void solve(){
  string L; cin >> L;
  list<char> result;
  auto iter = result.begin();
  for (int i = 0; i < L.size(); i++) {
    switch (L[i]) {
      case '<':
        if (iter != result.begin()) iter--;
        break;
      case '>':
        if (iter != result.end()) iter++;
        break;
      case '-':
        if (iter != result.begin()) result.erase((--iter)++);
        break;
      default:
        result.insert(iter, L[i]);
        break;
    }
  }
  for (char x : result) cout << x;
  cout << "\n";
}

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int T; cin >> T;
  while (T--) solve();
  return 0;
}
