#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef long long ll;

void solve(){
  int N, K; cin >> N >> K;
  int arr[K]; for (int i = 0; i < K; i++) cin >> arr[i];
  set<ll> s;
  int result = 0;
  for (int i = 0; i < K; i++) {
    assert(arr[i] >= 0);
    s.insert(arr[i]);
    if (s.size() <= N) continue;

    result++;
    map<int, int> m;
    for (auto ss : s) m[ss] = 9999;
    for (int j = i; j < K; j++) m[arr[j]] = min(m[arr[j]],j);

    int v = 0;
    int j = -1;
    for (auto [a,b] : m) {
      if (b > j) {
        v = a;
        j = b;
      }
    }
    s.erase(v);
  }
  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
