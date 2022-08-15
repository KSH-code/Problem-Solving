#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


const ll MOD = 1e9+7;

int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int dp[51][51][51][51];

ll dfs(int x, int a, int b, int c) {
    auto &ref = dp[x][a][b][c];
    if (ref != -1) return ref;
    if (!x) return 0;

    ref = 0;
    if (a-1 >= 0) ref = (ref + dfs(x-1,a-1,b,c)) % MOD;
    if (b-1 >= 0) ref = (ref + dfs(x-1,a,b-1,c)) % MOD;
    if (c-1 >= 0) ref = (ref + dfs(x-1,a,b,c-1)) % MOD;
    if (a-1 >= 0 && b-1 >= 0) ref = (ref + dfs(x-1,a-1,b-1,c)) % MOD;
    if (b-1 >= 0 && c-1 >= 0) ref = (ref + dfs(x-1,a,b-1,c-1)) % MOD;
    if (a-1 >= 0 && c-1 >= 0) ref = (ref + dfs(x-1,a-1,b,c-1)) % MOD;
    if (a-1 >= 0 && b-1 >= 0 && c-1 >= 0) ref = (ref + dfs(x-1,a-1,b-1,c-1)) % MOD;

    return ref;
}

void solve(){
    int N, a,b,c; cin >> N>>a>>b>>c;

    memset(dp, -1, sizeof dp);
    dp[0][0][0][0] = 1;

    cout << dfs(N,a,b,c);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
