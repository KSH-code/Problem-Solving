#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


const ll MOD = 1000000007;

int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N; cin >> N;

    ll dp[N+1][N+1]; memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 3; i++) {
        int z; cin >> z;
        for (int j = 1; j <= z; j++) {
            dp[j][j]++;
            for (int k = 1; k <= z; k++) {
                dp[j][k] += dp[j-1][k];
                dp[j][k] %= MOD;
            }
        }
    }

    ll result = 0;

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
