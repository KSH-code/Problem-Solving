#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
  {
    ll n, k;
    cin >> n >> k;
    ll mice[k];
    for (int i = 0; i < k; i++)
      cin >> mice[i];

    sort(mice, mice + k);

    ll a = 0;
    int r = 0;
    for (int i = k - 1; i >= 0; i--)
    {
      if (a + n - mice[i] < n)
      {
        a += n - mice[i];
        r++;
      }
    }
    cout << r << "\n";
  }

  return 0;
}
