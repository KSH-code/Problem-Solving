#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    int dp[N + 10];
    dp[1] = dp[3] = 999999;
    dp[0] = 0;
    dp[4] = 2;
    dp[2] = 1;
    for (int i = 5; i <= N; i++) dp[i] = min(dp[i - 5], dp[i - 2]) + 1;

    cout << (dp[N] >= 999999 ? -1 : dp[N]);
    return 0;
}
