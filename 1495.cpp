#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int N, S, M;
  cin >> N >> S >> M;
  int arr[N];

  for (int i = 0; i < N; i++)
    cin >> arr[i];

  bool dp[N][M + 1];

  for (int i = 0; i < N; i++)
    for (int j = 0; j <= M; j++)
      dp[i][j] = false;

  if (S + arr[0] <= M)
    dp[0][S + arr[0]] = true;
  if (S - arr[0] >= 0)
    dp[0][S - arr[0]] = true;

  for (int i = 1; i < N; i++)
  {
    int c = arr[i];
    for (int j = 0; j <= M; j++)
    {

      if (j + c <= M && dp[i - 1][j + c] || j - c >= 0 && dp[i - 1][j - c])
        dp[i][j] = true;
    }
  }

  for (int i = M; i >= 0; i--)
  {
    if (dp[N - 1][i])
    {
      cout << i;
      return 0;
    }
  }

  cout << -1;

  return 0;
}
