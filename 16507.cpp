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
    int N, M, K; cin >> N >> M >> K;

    int arr[N+1][M+1]; memset(arr, 0, sizeof arr);

    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
        cin >> arr[i][j];
        arr[i][j] += arr[i][j-1];
    }

    while (K--) {
        int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        int result = 0;
        for (int i = sx; i <= ex; i++) {
            result += arr[i][ey] - arr[i][sy-1];
        }

        cout << result/(ex-sx+1)/(ey-sy+1);
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
