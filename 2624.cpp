#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  ll T, k;
  cin >> T >> k;
  ll MAX = 1e5;
  ll dp[MAX];
  for (int i = 0; i < MAX; i++) dp[i] = 0;
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < b; j++) if (a * (j + 1) < MAX) dp[a * (j + 1)]++;
  }

  for (int i = 0; i <= T; i++) {
    dp[T] += dp[i] * dp[T - i];
  }

  cout << dp[T];
  return 0;
}
