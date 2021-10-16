#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
  {
    ll n;
    cin >> n;
    ll numbers[n];
    for (int i = 0; i < n; i++)
      cin >> numbers[i];
    sort(numbers, numbers + n);
    ll fl = -1;
    for (int z = 0; z < n; z++)
    {
      ll ss = numbers[z];
      int s = 0;
      for (int i = 0; i < n; i++)
        s += ss == numbers[i];
      if (s >= n / 2)
      {
        fl = -1;
        break;
      }
      unordered_map<ll, int> map;
      for (int i = z + 1; i < n; i++)
      {
        if (ss == numbers[i])
          continue;
        unordered_set<int> set;
        for (int j = 1; j * j <= numbers[i] - ss; j++)
        {
          if ((numbers[i] - ss) % j)
            continue;
          set.insert(j);
          set.insert((numbers[i] - ss) / j);
        }
        for (auto m : set)
          map[m]++;
      }

      ll result = -1;
      for (auto [r, c] : map)
      {
        if (c >= n / 2 - s && result < r)
          result = r;
      }
      fl = max(fl, result);
    }

    cout << fl << "\n";
  }

  return 0;
}
