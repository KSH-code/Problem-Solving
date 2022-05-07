#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N; cin >> N;
    int dp[1000000+1]; memset(dp, 0, sizeof(dp));

    int result = 1;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        dp[a] = max(dp[a], dp[a-1]+1);
        result = max(dp[a], result);
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
