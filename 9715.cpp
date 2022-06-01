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
    int N, M; cin >> N >> M;
    char arr[N+2][M+2]; memset(arr, '0', sizeof arr);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> arr[i][j];

    int result = 0;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
        for (int cur = '1'; cur <= arr[i][j]; cur++) {
            if (cur == '1') result+=2;
            for (int t = 0; t < 4; t++) {
                int nx = i+xxxx[t];
                int ny = j+yyyy[t];
                if (arr[nx][ny] < cur) result++;
            }
        }
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
