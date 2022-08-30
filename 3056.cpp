#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int N;
long double arr[20][20];

long double memo[1<<20];

long double dfs (int x, int mark) {
    if (x == N) return 1;
    auto &ref = memo[mark];
    if (ref > -1) return ref;

    ref = 0;
    for (int i = 0; i < N; i++) {
        if (mark & (1 << i)) {
            ref = max(
                dfs(x+1, mark - (1 << i)) * arr[x][i] / 100,
                ref
            );
        }
    }
    return ref;
}

void solve(){
    cin >> N;
    memset(memo, -1, sizeof memo);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];
    printf("%.6Lf", dfs(0,(1<<N)-1) * 100);
}

int main()
{
    // cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
