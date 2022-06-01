#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
const int MAX = 1e8;
const int MAX_SIZE = 1<<16;

int dp[MAX_SIZE][16];
int arr[16][16];
int N;

int tsp(int x, int visited) {
    if (visited+1 == 1<<N) return arr[x][0] ? arr[x][0] : MAX;
    if (dp[visited][x] < MAX) return dp[visited][x];

    int &result = dp[visited][x];

    for (int i = 0; i < N; i++) {
        if (visited&1<<i) continue;
        if (!arr[x][i]) continue;

        result = min(
            result,
            tsp(i, visited | 1<<i) + arr[x][i]
        );
    }

    return result;
}

void solve(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin>>arr[i][j];
    }

    for (int i = 0; i < MAX_SIZE; i++) for (int j = 0; j < N; j++) dp[i][j]=MAX;

    cout << tsp(0,1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
