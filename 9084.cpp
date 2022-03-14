#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

void solve(){
  int N, M; cin >> N;
  int dp[10001];
  int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
  cin >> M;
  for (int i = 0; i <= M; i++) dp[i] = 0;

  for (int i = 0; i < N; i++) {
    dp[arr[i]]++;
    for (int j = arr[i]; j <= M; j++) {
      dp[j] += dp[j - arr[i]];
    }
  }
  cout << dp[M] << '\n';
}

int main(){
  cin.tie(0) -> sync_with_stdio(0);
  int T; cin >> T;
  while(T--) solve();
  return 0;
}
