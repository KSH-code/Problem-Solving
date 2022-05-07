#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e4;

void solve(){
    int N; cin >> N;
    int A, B; cin >> A >> B;

    int arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);

    ll dp[N]; memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        if (i == 0) dp[i] = min(A*arr[i], B);
        else if (i > 0) dp[i] = dp[i-1] + arr[i] * A;

        for (int j = max(0, i - 39); j <= i; j++) {
            for (int m = j; m <= i; m++) {
                ll t = B;
                for (int k = j; k <= i; k++) t += abs(arr[m] - arr[k]) * A;
                if (j > 0) t += dp[j - 1];
                dp[i] = min(dp[i], t);
            }
        }
    }

    cout << dp[N-1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
