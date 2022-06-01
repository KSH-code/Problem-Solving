#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int N, M, C;
int arr[200];
int dp[10][1<<13];

int go (int x, int visited) {
    if (x == M) return 0;

    int &result = dp[x][visited];
    if (result != -1) return result;

    for (int i = 0; i < (1<<N); i++) {
        if (i&visited) continue;

        int remains = C;
        int count = 0;
        for (int j = 0; j < N; j++) if (1<<j&i) {
            remains -= arr[j];
            count++;
        }

        if (remains < 0) continue;

        result = max(
            result,
            count+go(x+1, visited|i)
        );
    }

    return result;
}

void solve(){
    cin >> N >> M >> C;

    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < 10; i++) for (int j = 0; j < (1<<13); j++) dp[i][j]=-1;

    cout << go(0, 0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
