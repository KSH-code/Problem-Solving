#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N, M; cin >> N >> M;
    int arr[N][M]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
            int a;cin>>a;
            cout << arr[i][j]+a << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        // cout << '\n';
    }
    return 0;
}
