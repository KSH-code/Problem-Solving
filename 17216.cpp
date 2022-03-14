#include <iostream>
using namespace std;

int main() {
  cin.tie(0) -> sync_with_stdio(0);

  int N; cin >> N;
  int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

  int dp[N];
  dp[0] = arr[0];
  int result = 0;
  for (int i = 1; i < N; i++) {
    dp[i] = arr[i];
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[i]) dp[i] = max(dp[i], dp[j] + arr[i]);
    }
    result = max(result, dp[i]);
  }

  cout << result;
  return 0;
}
