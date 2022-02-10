#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  int N; cin >>N;
  unordered_map<ll, int> m;
  while (N--) {
    ll a; cin >> a;
    if (m.find(a) == m.end()) m[a] = 0;
    m[a]++;
  }

  ll count = 0;
  ll result = 0;
  for (auto [a, n_count] : m) {
    if (count < n_count) count = n_count, result = a;
    if (count == n_count) result = min(result, a);
  }
  cout << result;
  return 0;
}
