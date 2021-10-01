#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int distances[505][505];
int memoize[505][505];
vector<pair<int, int>> points;

int dp(int n, int k)
{
  if (n == 1)
    return 0;
  if (memoize[n][k] >= 0)
    return memoize[n][k];

  memoize[n][k] = 99999999;

  for (int i = 0; i <= k; i++)
  {
    if (n - i - 1 <= 0)
      break;

    memoize[n][k] = min(
        memoize[n][k],
        dp(n - i - 1, k - i) + abs(points[n - 1].first - points[n - i - 2].first) + abs(points[n - 1].second - points[n - i - 2].second));
  }
  return memoize[n][k];
}

int main()
{
  int N, K;
  scanf("%d%d", &N, &K);

  for (int i = 0; i < N; i++)
  {
    int x, y;
    scanf("%d%d", &x, &y);
    points.push_back({x, y});
  }

  memset(memoize, -1, sizeof(memoize));

  printf("%d", dp(N, K));
  return 0;
}
