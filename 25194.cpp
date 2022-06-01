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
    int arr[N+1]; for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    bool dp[N+1][7]; memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int k = 0; k < i; k++)
        for (int j = 0; j < 7; j++) {
            if (!dp[k][j]) continue;

            int mark = (j + arr[i])%7;
            dp[i][mark] = dp[k][j];
            if (mark==4) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
