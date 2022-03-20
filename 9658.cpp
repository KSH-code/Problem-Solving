#include <iostream>
using namespace std;

typedef long long ll;

const int SANG = 1;
const int CHANG = 2;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N; int dp[10000]; cin >> N;
  dp[1] = CHANG;
  dp[2] = SANG;
  dp[3] = CHANG;
  dp[4] = SANG;
  for (int i = 5; i <= N; i++) {
    int sk = (dp[i - 4] == SANG) + (dp[i - 3] == SANG) + (dp[i - 1] == SANG);
    dp[i] = sk < 3 ? SANG : CHANG;
  }
  cout << (dp[N] == SANG ? "SK" : "CY");
  return 0;
}
// 지는순서
// 1 2 3 4 5 6 7 8 9
// 시 반 시 반 반 s c s c
