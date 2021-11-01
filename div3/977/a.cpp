#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;
  while (k--)
  {
    n = n % 10 > 0 ? n - 1 : n / 10;
  }
  cout << n;
  return 0;
}
