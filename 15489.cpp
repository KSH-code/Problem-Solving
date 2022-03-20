#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int R, C, W; cin >> R >> C >> W;
    ll dp[100][100];
    dp[0][0] = 1;
    for (int i = 1; i < 100; i++){
        dp[i][0] = 1;
        for (int j = 1; j <= 99; j++)  {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    ll result = 0;
    for (int i = 0; i < W; i++) {
        for (int j = 0; j <= i; j++) {
            result += dp[i + R - 1][j + C - 1];
        }
    }

    cout << result;

    return 0;
}
