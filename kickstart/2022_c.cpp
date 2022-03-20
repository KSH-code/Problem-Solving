#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

void solve(){
  int N; string str;
  cin >> N >> str;
  bool dp[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) dp[i][j] = false;
    dp[i][i] = true;
  }

  for (int count = 1; count < N; count++) {
    for (int i = 0; i < N; i++) {
      int j = i + count;
      if (j >= N) break;

      if (dp[i+1][j-1]) {
        if (str[i] == '?') {
          if (str[j] == '1') str[i] = '0';
          else str[i] = '1';
        }
        if (str[j] == '?') {
          if (str[i] == '1') str[j] = '0';
          else str[j] = '1';
        }
        if (str[j] == str[i]) {
          if (count >= 4) {
            cout << "IMPOSSIBLE";
            return;
          }
          dp[i][j] = dp[i+1][j-1];
        }
      }
    }
  }
  cout << "POSSIBLE";
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
