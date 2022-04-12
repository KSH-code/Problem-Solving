#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5;

bool solve(){
  ll N; cin >> N;
  if (N==0) return false;
  if (N == 0) {
    cout << 0;
    return true;
  }

  bool tp[MAX+1]; memset(tp, 1, sizeof(tp));
  vector<ll> primes;
  ll s = 1;
  for (ll i = 2; i <= MAX;i++) {
    if (!tp[i]) continue;
    if (N % i == 0) {
      primes.push_back(i);
      while (N % (s * i) == 0) s *= i;
    }
    for (int j = i+i; j<=MAX; j+=i) tp[j] = false;
  }

  if (s < N && N % s == 0) primes.push_back(N/s);
  ll result = 0;

  for (int i = 1; i < (1<<primes.size()); i++) {
    int count = 0;
    ll r = 1;
    for (int j = 0; (1<<j) <= i; j++) {
      if (i & (1<<j)) {
        count++;
        r *= primes[j];
      }
      if (r > N) {
        count = 0;
        break;
      }
    }

    if (count == 0) continue;

    if (count % 2) {
      result -= N / r;
    } else {
      result += N / r;
    }
  }

  cout << N+result;
  return true;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  while (solve()) cout << '\n';
  return 0;
}
