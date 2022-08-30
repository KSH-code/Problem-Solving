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
    N = 1 << N;
    int arr[N][N];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> arr[i][j];

    while(M--){
        int size; cin >> size;
        size = 1<<size;
        int sx = 0;
        int sy = 0;
        while (1) {
            if (sy == N) {
                sy = 0;
                sx += size;
            }
            if (sx == N) break;
            int tr[size][size]; for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) tr[i][j] = arr[sx+size-1-j][sy+i];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    arr[sx+i][sy+j] = tr[i][j];
                }
            }
            sy += size;
        }
        queue<pair<int,int>> q;
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < N; y++) {
                if (!arr[x][y]) continue;
                int count = 0;
                for (int c = 0; c < 4; c++) {
                    int nx = x+xxxx[c];
                    int ny = y+yyyy[c];
                    if (nx < 0 || nx >= N || ny >= N || ny < 0) continue;
                    if (arr[nx][ny]) count++;
                }
                if (count <= 2) q.push({x,y});
            }
        }
        while (q.size()) {
            auto [x,y] = q.front(); q.pop();
            arr[x][y]--;
        }
    }
    int count = 0;
    queue<pair<int,int>> q;
    bool visited[N][N]; memset(visited, 0, sizeof visited);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int tc = 0;
        if (!visited[i][j] && arr[i][j]) {
            q.push({i,j});
            visited[i][j]=true;
            tc++;
        }
        while (q.size()) {
            auto [x,y] = q.front(); q.pop();
            for (int c = 0; c < 4; c++) {
                int nx = x+xxxx[c];
                int ny = y+yyyy[c];
                if (nx < 0 || nx >= N || ny >= N || ny < 0) continue;
                if (visited[nx][ny] || !arr[nx][ny]) continue;
                tc++;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        count = max(count, tc);
    }
    int result = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) result += arr[i][j];
    cout << result << '\n';
    cout << count;
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
