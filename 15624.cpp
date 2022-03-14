#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAX = 1e6 + 1;
const ll DIVIDER = 1e9 + 7;
int main(){
  int N; cin >> N;
  ll dp[MAX]; dp[0] = 0; dp[1] = 1;
  for (int i = 2; i <= N; i++) dp[i] = (dp[i-1] + dp[i-2]) % DIVIDER;
  cout << dp[N];
  return 0;
}
