#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

ll dp[500];

void solve(){
    ll N; cin >> N;

    dp[0] = dp[1] = 1;
    int l = 1;
    for (int i = 2; i < 500; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        if (dp[i] > N) break;
        else l = i;
    }

    for (int i = l; i >= 1; i--) {
        if (dp[i] <= N) {
            N -= dp[i];
            cout << 1;
        } else {
            cout << 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
