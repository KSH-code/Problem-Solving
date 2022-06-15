#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int N; cin >> N;
  N = N*2+1;
  int str[N];
  for (int i = 0; i <N; i++) {
    if (i % 2) cin >> str[i];
    else str[i] = -1;
  }

  int dp[N]; for (int i = 0; i < N; i++) dp[i] = 1;

  int c = 0, r = 0;
  for (int i = 0; i < N; i++) {
    int radius = min(r - i, dp[c * 2 - i]);
    while (i - radius >= 0 && i + radius < N && str[i - radius] == str[i + radius]) radius++;
    radius--;
    dp[i] = radius;
    if (r <= i + radius) {
      r = i + radius;
      c = i;
    }
  }

  int M; cin >> M;
  while (M--) {
    int s,e; cin >> s >> e;
    int m = s+e;
    cout << (dp[m-1] >= e-s) << '\n';
  }
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
