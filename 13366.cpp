#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

void solve(){
  string str; cin >> str;
  int result = 0; for (int i = 0; i < str.size(); i++) result+=str[i]-'0';
  cout << (result % 9 ? "NO" : "YES");
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T; while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
