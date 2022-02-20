#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  ll N; cin >> N;
  ll dp[1000];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  for (int i = 3; i <= N; i++) {
    dp[i] = dp[i - 1] + 1;
    for (int j = 0; j <= i - 2; j++) {
      dp[i] = max(dp[i], dp[j] * (i - j - 2) + dp[j]);
    }
  }

  cout << dp[N];
  return 0;
}
