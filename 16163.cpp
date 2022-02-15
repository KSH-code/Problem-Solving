#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  string temp; cin >> temp;
  int n = temp.size() * 2 + 1;
  char str[n];
  for (int i = 0; i < temp.size(); i++)
  {
    str[i * 2] = '*';
    str[i * 2 + 1] = temp[i];
  }
  str[n - 1] = '*';

  int dp[n]; for (int i = 0; i < n; i++) dp[i] = 1;
  ll result = 0;

  int c = 0, r = 0;
  for (int i = 0; i < n; i++) {
    int radius = min(r - i, dp[c * 2 - i]);
    while (i - radius >= 0 && i + radius < n && str[i - radius] == str[i + radius]) radius++;
    dp[i] = radius;

    if (r <= i + radius) {
      r = i + radius;
      c = i;
    }

    result += radius / 2;
  }

  cout << result;
  return 0;
}
