#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[60][45][30][28];
int counts[6];
ll N, K;
ll dfs(ll n, int k) {
    if (!n || k == K) return n;
    if (dp[counts[2]][counts[3]][counts[4]][counts[5]]) return dp[counts[2]][counts[3]][counts[4]][counts[5]];

    ll result = n;
    for (int i = 2; i <= 5; i++) {
        counts[i]++;
        result = min(result, dfs(n/i, k+1) + n%i);
        counts[i]--;
    }
    return dp[counts[2]][counts[3]][counts[4]][counts[5]] = result;
}
int main()
{
    cin >> N >> K;
    cout << dfs(N, 1);
    return 0;
}
