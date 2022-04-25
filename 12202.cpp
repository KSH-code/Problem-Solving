#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[100];
int dp[100][100];
int K;
int dfs(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r]!=-1) return dp[l][r];
    if (r-l+1<=2) return dp[l][r]=r-l+1;

    dp[l][r] = 9999;
    for (int i = l+1; i < r; i++) {
        int a = dfs(l+1,i-1);
        int b = dfs(i+1,r-1);
        if (a+b == 0 && arr[r]-arr[i]==K && arr[i]-arr[l]==K) {
            return dp[l][r]=0;
        }
        dp[l][r]=min(dp[l][r], a+b+3);
    }
    for (int i = l; i <= r; i++) {
        dp[l][r] = min(dfs(l, i) + dfs(i+1, r), dp[l][r]);
    }
    return dp[l][r];
}

void solve(){
    int N; cin >> N >> K;

    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = -1;
/*
1 6 4
2 6 10 14 18 10
*/

    cout << dfs(0, N-1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T;cin>>T;
    for (int i = 1;i <= T; i++){
        cout << "Case #"<<i<<": ";
        solve();
        cout << '\n';
    }
    return 0;
}
