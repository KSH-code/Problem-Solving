#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;
const ll LIMIT = 1e18;

void solve(){
    int N; cin >> N;
    pair<ll,ll> arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;

    ll dp[N][MAX+2]; memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) for (int j = 0; j <= MAX+1; j++) dp[i][j] = LIMIT;

    for (int i = 0; i < N; i++) {
        auto [x,y] = arr[i];
        x--;
        dp[i][x] = y;
        if (i == 0) continue;

        x--;
        for (int j = 0; j <= MAX; j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j - x >= 0) dp[i][j] = min({dp[i][j], dp[i-1][j-x]+y});
        }
    }

    int computers; cin >> computers;
    ll result = dp[N-1][computers];
    if (computers == 1) result = 0;
    result = result == LIMIT ? -1 : result;
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
