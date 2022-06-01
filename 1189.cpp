#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

bool visited[5][5];
int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};
int N,M,K;
string arr[5];
int result = 0;

void dfs(int x, int y, int count) {
    if (count == K) {
        if (x == 0 && M==y+1) result++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x+xxxx[i];
        int ny = y+yyyy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny] || arr[nx][ny] == 'T') continue;
        visited[nx][ny] = true;
        dfs(nx,ny,count+1);
        visited[nx][ny] = false;
    }
}

void solve(){
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    visited[N-1][0] = true;
    dfs(N-1,0,1);
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
