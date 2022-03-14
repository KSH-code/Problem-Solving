#include <iostream>
#include <algorithm>
using namespace std;

int c[41];
int dp[42];

int main(){
  int N, M; cin >> N >> M;
  while (M--) {
    int a; cin >> a;
    c[a]++;
  }
  int result = 1;
  dp[1] = 1;
  dp[0] = 0;
  for (int i = 2; i <= N; i++) {
    if (c[i]) {
      result *= max(1, dp[i - 1]);
    } else {
      if (c[i - 1]) {
        dp[i] = 1;
      } else dp[i] = dp[i - 1] + max(1, dp[i - 2]);
    }
  }
  cout << result * max(1, dp[N]);
  return 0;
}
