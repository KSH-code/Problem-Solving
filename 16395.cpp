#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  ll dp[31][31];
  for (int i = 1; i <= 30; i++) {
    dp[i][i] = dp[i][1] = 1;
    for (int j = 2; j < i; j++) {
      dp[i][j] = dp[i-1][j - 1] + dp[i-1][j];
    }
  }

  int n,k;
  cin >> n >> k;
  cout << dp[n][k];
  return 0;
}
