#include <iostream>
using namespace std;
typedef long long ll;

const ll MODULES = 1e9+3;

ll dp[1002][1002];
void solve(){
  int N, K; cin >> N >> K;
  if (K == 1) {
    cout << N;
    return;
  }

  dp[1][1] = 1;
  dp[2][1] = 2;
  for (int i = 3; i <= N; i++) {
    dp[i][1] = i;
    for (int j = 2; j <= K; j++) {
      dp[i][j] = (dp[i-2][j-1] + dp[i-1][j]) % MODULES;
    }
  }

  cout << (dp[N-1][K] + dp[N-3][K-1]) % MODULES;
}
int main (){
  solve();
  return 0;
}
