#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
  ll N, K;
  ll mod = 1e9 + 7;

  cin >> N >> K;

  if (N == K || !K)
  {
    cout << 1;
    return 0;
  }
  ll result = 1;
  for (int i = 1; i <= N; i++)
    result = (i * result) % mod;

  ll base = 1;
  for (int i = 2; i <= N - K; i++)
    base = (base * i) % mod;
  for (int i = 2; i <= K; i++)
    base = (base * i) % mod;
  ll inverse = 1;
  ll p = mod - 2;
  while (p)
  {
    if (p % 2)
      inverse = (inverse * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  cout << (result * inverse) % mod;

  return 0;
}
