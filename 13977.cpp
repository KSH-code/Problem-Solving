#include <iostream>
using namespace std;
typedef long long ll;
ll fact[4000001];
int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  ll mod = 1e9 + 7;
  fact[1] = 1;
  for (int i = 2; i <= 4000000; i++)
    fact[i] = (fact[i - 1] * i) % mod;

  int M;
  cin >> M;
  while (M--)
  {
    ll N, K;

    cin >> N >> K;
    if (N == K || !K)
    {
      cout << 1 << "\n";
      continue;
    }

    ll result = fact[N];

    ll base = (fact[K] * fact[N - K]) % mod;
    ll inverse = 1;
    ll p = mod - 2;
    while (p)
    {
      if (p % 2)
        inverse = (inverse * base) % mod;
      base = (base * base) % mod;
      p /= 2;
    }
    cout << (result * inverse) % mod << "\n";
  }

  return 0;
}
