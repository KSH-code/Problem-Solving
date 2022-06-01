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
    int arr[N+1][4]; memset(arr, 0, sizeof arr);

    for (int i = 1; i <= N; i++) {
        int c; cin >> c;
        arr[i][c]++;
        for (int j = 1; j <= 3; j++) arr[i][j] += arr[i-1][j];
    }

    while(M--) {
        int a,b;cin>>a>>b;

        for (int i = 1; i <= 3; i++) {
            cout << arr[b][i]-arr[a-1][i]<< ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
