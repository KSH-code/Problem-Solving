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
    int arr[N][M]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) arr[i][j] = 1;
    int z;
    cin >> z;
    while (z--) {
        int a,b;cin >> a >> b;
        arr[--a][--b] = 2;
    }
    cin >> z;
    while (z--) {
        int a,b;cin >> a >> b;
        arr[--a][--b] = 3;
    }
    cin >> z;
    while (z--) {
        int a,b;cin >> a >> b;
        arr[--a][--b] = 4;
    }

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        switch(arr[i][j]) {
            case 3:{
                int xxxx[] = {-1,-2,-2,-1,1,2,2,1};
                int yyyy[] = {-2,-1,1,2,2,1,-1,-2};
                for (int c = 0; c < 8; c++) {
                    int nx = i;
                    int ny = j;
                    nx += xxxx[c];
                    ny += yyyy[c];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 1) arr[nx][ny] = 0;
                }}
            break;
            case 2:{
                for (int c = 0; c < 8; c++) {
                    int nx = i;
                    int ny = j;
                    while (1) {
                        nx += xxxx[c];
                        ny += yyyy[c];
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                            if (arr[nx][ny] == 1 || arr[nx][ny] == 0) arr[nx][ny] = 0;
                            else break;
                        else break;
                    }
                }}
            break;
        }
    }
    int result = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (arr[i][j]==1) {
        result++;
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
