#include <iostream>
using namespace std;
typedef long long ll;

const ll MAX = 1e9;

void solve(){
    int N; cin >> N;
    ll dp[N+10][10][1024]; for (int i = 0; i <= N; i++) for (int j = 0; j < 10; j++) for (int k = 0; k < 1024; k++) dp[i][j][k] = 0;

    int xx[10][2] = {
        {-1, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 5},
        {4, 6},
        {5, 7},
        {6, 8},
        {7, 9},
        {8, -1}
    };
    for (int i = 1; i < 10; i++) dp[1][i][1<<i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 1024; k++) {
                for (auto x : xx[j]) {
                    if (x == -1) continue;
                    dp[i][j][k | (1<<j)] = (dp[i][j][k | (1<<j)] + dp[i-1][x][k]) % MAX;
                }
            }
        }
    }
    ll result = 0;
    for (int i = 0; i < 10; i++) {
        result = (result + dp[N][i][1023]) % MAX;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
