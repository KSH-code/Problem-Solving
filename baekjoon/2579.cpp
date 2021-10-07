#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;

  int map[N];
  for (int i = 0; i < N; i++)
    cin >> map[i];

  int dp[N][3];
  dp[0][0] = 0;
  dp[0][2] = dp[0][1] = map[0];
  for (int i = 1; i < N; i++)
  {
    dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = dp[i - 1][0] + map[i];
    dp[i][2] = dp[i - 1][1] + map[i];
  }

  int result = max(dp[N - 1][1], dp[N - 1][2]);
  printf("%d", result);
  return 0;
}
