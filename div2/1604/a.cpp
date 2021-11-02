#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    ll max = 0, temp, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> temp;
      max = (temp - 1 - i) > max ? (temp - 1 - i) : max;
    }
    cout << max << endl;
  }
  return 0;
}
