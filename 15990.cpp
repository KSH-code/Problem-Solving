#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int T; cin >>T;

  int max = 1e5 + 1;
  ll dp[max][4];
  for (int i = 1; i < max; i++) dp[i][1] = dp[i][2] = dp[i][3] = 0;
  dp[3][3] = dp[3][1] = dp[3][2] = dp[2][2] = dp[1][1] = 1;

  ll m = 1e9 + 9;
  for (int i = 4; i < max; i++) {
    dp[i][1] = (dp[i - 1][3] + dp[i - 1][2]) % m;
    dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % m;
    dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % m;
  }

  while (T--) {
    int a; cin >> a;
    ll result = 0;
    for (int i = 1; i <= 3; i++) result = (result + dp[a][i]) % m;

    cout << result << '\n';
  }
  return 0;
}
