#include <iostream>
using namespace std;

const int KEEPED = 0;
const int REMOVED = 1;
const int FIRST_SELECTED = 2;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int N; cin >> N;
  int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
  if (N == 1) {
    cout << arr[0];
    return 0;
  }

  int dp[N][3];
  dp[0][KEEPED] = arr[0];
  dp[0][REMOVED] = -1e9;
  dp[0][FIRST_SELECTED] = -1e9;
  int result = -1e9;
  for (int i = 1; i < N; i++) {
    dp[i][KEEPED] = max(dp[i-1][KEEPED], dp[i-1][FIRST_SELECTED]) + arr[i];
    dp[i][REMOVED] = max(dp[i-1][FIRST_SELECTED] + arr[i], max(dp[i-1][KEEPED], dp[i-1][REMOVED] + arr[i]));
    dp[i][FIRST_SELECTED] = arr[i];
    for (int j = 0; j < 3; j++) {
      result = max(result, dp[i][j]);
    }
  }

  cout << result;
  return 0;
}
