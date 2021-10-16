#include <iostream>
#include <algorithm>

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
    if (numbers[0] == numbers[n - 1])
    {
      cout << -1 << "\n";
      continue;
    }

    ll result = 0;
    for (int i = 1; i < n; i++)
    {
      result = gcd(numbers[i] - numbers[0], result);
    }

    cout << result << "\n";
  }

  return 0;
}
