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
    int N, K; cin >> N >> K;
    int dp[N+1][K]; memset(dp, 0, sizeof dp);

    pair<int,int> arr[K]; for (auto &[x,y]:arr) cin >> y >> x;

    int result = 0;
    for (int j = 0; j < K; j++) {
        auto [x,y] = arr[j];
        for (int i = 0; i <= N; i++) {
            if (j==0) {
                if (i >= x) dp[i][j] = y;
            } else if (i-x>=0) dp[i][j] = max({dp[i-x][j-1]+y, dp[i][j-1]});
            else dp[i][j] = dp[i][j-1];
            result = max({result, dp[i][j]});
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
