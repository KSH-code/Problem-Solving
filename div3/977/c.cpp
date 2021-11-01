#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;

  vector<ll> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  sort(arr.begin(), arr.end());
  if (k == 0 && arr[0] > 1)
  {
    cout << 1;
    return 0;
  }
  ll last = -1;
  ll lc = 0;
  ll tc = 0;
  for (auto i : arr)
  {
    if (last == i)
    {
      lc += 1;
    }
    else
    {
      tc += lc;
      lc = 1;
      if (tc == k)
      {
        cout << last;
        return 0;
      }
      last = i;
    }
  }
  tc += lc;
  cout << (tc == k ? last : -1);
  return 0;
}
