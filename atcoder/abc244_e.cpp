#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const ll MAX = 998244353;
vector<pair<int,int>> edges;
int N, M, K, S, T, X;
void solve(){
  cin >> N >> M >> K >> S >> T >> X;
  for (int i = 0; i < M; i++){
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
  }
  ll dp[2002][2002][2]; for (int i = 0; i <=N; i++) for (int j = 0; j <=N; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = 0;
  dp[0][S][0] = 1;
  for (int i = 0; i < K; i++) {
    for (auto [u,v] : edges) {
      for (int k = 0; k < 2; k++) {
        dp[i+1][v][k ^ (v == X)] = (dp[i][u][k] + dp[i+1][v][k ^ (v == X)]) % MAX;
        dp[i+1][u][k ^ (u == X)] = (dp[i][v][k] + dp[i+1][u][k ^ (u == X)]) % MAX;
      }
    }
  }
  cout << dp[K][T][0];
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
