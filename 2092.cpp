#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int T, A, S, B;
int counts[201];

const int MOD = 1e6;

int memo[201][4001];

void solve(){
    cin >> T >> A >> S >> B;
    while(A--) {
        int a; cin >> a;
        counts[a]++;
        memo[a][counts[a]]++;
    }

    int result = 0;

    for (int x = 1; x <= T; x++) {
        for (int i = 1; memo[x][i]; i++) {
            for (int nx = x + 1; nx <= T; nx++) {
                for (int j = 1; j <= counts[nx]; j++) {
                    memo[nx][i + j] += memo[x][i];
                    memo[nx][i + j] %= MOD;
                }
            }
        }
    }

    for (int i = 1; i <= T; i++) for (int j = S; j <= B; j++) {
        result = (result + memo[i][j]) % MOD;
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
