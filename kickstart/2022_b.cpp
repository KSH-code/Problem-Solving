#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

string min(string a, string b) {
  if (a.size() > b.size()) return b;
  else if (a.size() < b.size()) return a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) continue;

    if (a[i] < b[i]) return a;
    else return b;
  }
  return a;
}

void solve(){
  string str; cin >> str;
  ll z = 0; for (int i = 0; i < str.size(); i++) z += str[i] - '0';
  z = (9 - z % 9) % 9;

  string result = "99" + str;
  string temp = "";
  for (int i = 0; i < str.size(); i++) {
    if (!(i == 0 && z == 0) && str[i] > z + '0') {
      string c = temp;
      c += z + '0';
      for (int j = i; j < str.size(); j++) {
        c += str[j];
      }
      result = min(result, c);
      cout << result;
      return;
    }
    temp += str[i];
  }
  result = min(result, temp += z + '0');
  cout << result;
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #"<<i<<": ";
    solve();
    cout << "\n";
  }
  return 0;
}
