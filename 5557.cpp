#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N; cin >> N;
    int arr[N+1]; for (int i = 1; i <= N; i++) cin >> arr[i];
    ll dp[N+1][21]; memset(dp, 0, sizeof dp);

    ll result = 0;
    dp[1][arr[1]] = 1;
    for (int i = 2; i <= N-1; i++) {
        for (int j = -1; j <= 1; j+=2) {
            if (i == 1 && j == -1) continue;
            for (int k = 0; k <= 20; k++) {
                int n = arr[i] * j + k;
                if (n < 0 || n > 20) continue;

                dp[i][n] += dp[i-1][k];
            }
        }
    }

    cout << dp[N-1][arr[N]];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
