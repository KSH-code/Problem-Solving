#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
int M;

ll dp[51][2501];

ll dfs(int N, int remains) {
    if (dp[N][remains]) return dp[N][remains];

    if (N == 1) {
        return dp[N][remains] = min(remains, M);
    }

    ll result = 0;
    for (int i = 1; i <= M; i++) {
        if (i >= remains) break;
        result += dfs(N-1, remains-i);
        result %= MOD;
    }

    return dp[N][remains] = result % MOD + MOD;
}

void solve(){
    int N, K; cin >> N >> M >>K;
    cout << dfs(N, K) % MOD;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
