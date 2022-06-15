#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 32768;
void solve(){
    int memo[4][MAX]; memset(memo, 0, sizeof memo);
    for (int i = 0; i*i < MAX; i++) {
        memo[0][i*i]++;
        for (int t = 1; t <= 3; t++) {
            for (int j = i*i; j < MAX; j++) memo[t][j] += memo[t-1][j-i*i];
        }
    }

    while (1) {
        int N; cin >> N;
        if (!N) return;

        cout << memo[3][N] << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
