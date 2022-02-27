#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[501][501];
ll N, arr[501][2];

ll dfs(int s, int e){
    if (s >= e) return 0;
    if (dp[s][e]) return dp[s][e];
    if (s + 1 == e) return dp[s][e] = arr[s][0] * arr[s][1] * arr[e][1];

    ll result = (ll)1e11;
    for (int i = s; i < e; i++) {
        ll d = dfs(s, i) + arr[s][0] * arr[i][1] * arr[e][1] + dfs(i + 1, e);
        result = min(result, d);
    }
    return dp[s][e] = result;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N; for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1];
    cout << dfs(0, N - 1);
    return 0;
}
