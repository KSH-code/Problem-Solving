#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;


void solve(){
  int N; cin >> N;
  string str; cin >> str;
  int K; cin >> K;
  for (int i = 0; i < min((int)str.size(),K); i++) {
    if (str[str.size()-i-1] == '1') {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
}

int main (){
  cin.tie(0) -> sync_with_stdio(0);

  solve();
  return 0;
}
