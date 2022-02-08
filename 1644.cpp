#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  ll n = 1e6 * 4;
  bool *is_prime = new bool[n + 1];
  for (int i = 2; i <= n; i++)
    is_prime[i] = true;

  vector<int> prime;
  for (ll i = 2; i <= n; i++)
  {
    if (is_prime[i])
    {
      for (ll j = i * 2; j <= n; j += i)
        is_prime[j] = false;
      prime.push_back(i);
    }
  }

  ll N;
  cin >> N;
  int l = 0, r = 1, count = 0;
  ll sum = prime[0];
  while (l < prime.size())
  {
    if (N == sum)
      count++;

    if (sum >= N)
      sum -= prime[l++];
    else if (prime.size() > r)
      sum += prime[r++];
    else
      break;
  }

  cout << count;
  return 0;
}
