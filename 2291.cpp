#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

ll dp[11][221][221];

ll dfs(int N, int cur, int M) {
    if (!N && !M) return 1;
    if (!N) return 0;

    ll &ret = dp[N][cur][M];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = cur; i <= 220; i++) {
        if (M-i<0) break;
        ret += dfs(N-1, i, M-i);
    }

    return ret;
}

void trace(int N, int cur, int M, ll K) {
    if (N == 0) return;

    for (int i = cur; i <= 220; i++) {
        ll lc = dfs(N-1, i, M-i);
        if (lc <= K) {
            K -= lc;
        } else {
            cout << i << ' ';
            trace(N-1, i, M-i, K);
            return;
        }
    }
}

void solve(){
    memset(dp, -1, sizeof dp);
    ll N, M, K; cin >> N >> M >>K;
    trace(N, 1, M, K-1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
