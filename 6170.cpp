#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int dp[N][2];
    dp[0][1] = dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }
    cout << dp[N-1][0]+dp[N-1][1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Scenario #"<<i<<":\n";
        solve();
        cout <<"\n\n";
    }
    return 0;
}
