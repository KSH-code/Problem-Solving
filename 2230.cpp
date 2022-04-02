#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void solve(){
  ll N,M;cin>>N>>M;
  ll arr[N]; for (int i = 0;i<N;i++) cin>>arr[i];
  sort(arr,arr+N);

  ll result = 1e10;
  for (int i = 0; i < N; i++) {
    ll m = arr[i];
    auto it = lower_bound(arr, arr+N, m+M);
    if (it == arr+N || it == arr+i) continue;
    result = min(result, *it - m);
  }

  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
