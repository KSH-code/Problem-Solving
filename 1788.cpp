#include <iostream>
using namespace std;

int base = 1e6;
int dp[3000000];

int main(){
  dp[base] = 0;
  dp[base + 1] = 1;
  for(int i = 2; i <= base; i++){
    dp[base + i] = (dp[base + i - 1] + dp[base + i - 2]) % (int) 1e9;
  }

  for (int i = 1; i <= base; i++){
    dp[base - i] = (dp[base - i + 2] - dp[base - i + 1]) % (int) 1e9;
  }

  int N; cin >> N; N += base;
  cout << (dp[N] < 0 ? -1 : dp[N] == 0 ? 0 : 1) << endl;
  cout << abs(dp[N]);
  return 0;
}
