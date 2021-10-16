#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--)
  {
    ll candidates[3];
    cin >> candidates[0] >> candidates[1] >> candidates[2];

    for (int i = 0; i < 3; i++)
    {
      ll result = 0;
      for (int j = 0; j < 3; j++)
      {
        if (i == j)
          continue;
        if (candidates[i] <= candidates[j])
          result = max(result, abs(candidates[i] - candidates[j]) + 1);
      }
      cout << result << " ";
    }
    cout << "\n";
  }
  return 0;
}
