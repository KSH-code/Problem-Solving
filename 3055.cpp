#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;

void solve(){
    int N, M; cin >> N >> M;
    string arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];

    int waters[N][M];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) waters[i][j] = 10000;

    queue<tuple<int,int,int>> q;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (arr[i][j] == '*') {
        q.push({i,j,0});
        waters[i][j]=0;
    }

    int xxxx[]={-1,0,1,0};
    int yyyy[]={0,1,0,-1};

    while (q.size()) {
        auto [x,y,_] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x+xxxx[i];
            int ny = y+yyyy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 'X' || arr[nx][ny] == 'D') continue;
            if (waters[nx][ny] <= waters[x][y] + 1) continue;
            waters[nx][ny] = waters[x][y] + 1;
            q.push({nx,ny,0});
        }
    }

    bool visited[N][M]; memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (arr[i][j] == 'S') {
        q.push({i,j,0});
        visited[i][j]=true;
    }

    while (q.size()) {
        auto [x,y,c] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x+xxxx[i];
            int ny = y+yyyy[i];
            int nc = c+1;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 'X') continue;
            if (visited[nx][ny]) continue;
            if (nc >= waters[nx][ny]) continue;
            if (arr[nx][ny] == 'D') {
                cout << nc;
                return;
            }
            visited[nx][ny] = true;
            q.push({nx,ny,nc});
        }
    }
    cout << "KAKTUS";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
