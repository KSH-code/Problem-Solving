#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][2][31];
int main(){
  cin.tie(0) -> sync_with_stdio(false);
  int T, W; cin >> T >> W;
  int c; cin >> c;
  dp[0][0][0] = c == 1;
  dp[0][1][1] = c == 2;
  for (int i = 1; i < T; i++) {
    cin >> c;
    // if stay
    for (int j = 0; j <= W; j++) {
      dp[i][0][j] = dp[i-1][0][j] + (int)(c == 1);
      dp[i][1][j] = dp[i-1][1][j] + (int)(c == 2);
    }
    // if move
    for (int j = 1; j <= W; j++) {
      dp[i][0][j] = max(dp[i][0][j], dp[i-1][1][j-1] + (int)(c == 1));
      dp[i][1][j] = max(dp[i][1][j], dp[i-1][0][j-1] + (int)(c == 2));
    }
  }

  int result = 0;
  for (int i = 0; i < T; i++) {
    for (int j = 0; j <= W; j++) {
      result = max(result, dp[i][0][j]);
      result = max(result, dp[i][1][j]);
    }
  }

  cout << result;
  return 0;
}
