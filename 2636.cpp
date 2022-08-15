#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

using pii = pair<int,int>;
void solve(){
    int N, M; cin >> N >> M;
    int arr[N][M]; for (int i= 0; i < N; i++) for (int j = 0;j <M;j++) cin >> arr[i][j];

    int bc = 0;
    for (int result = 0; 1; result++) {
        bool visited[N][M]; memset(visited, 0, sizeof visited);

        int count = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) count += arr[i][j] == 1;

        if (!count) {
            cout << result << '\n' << bc;
            return;
        }

        queue<pii> q;
        q.push({0,0});

        while (q.size()) {
            auto [x,y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x+xxxx[i];
                int ny = y+yyyy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (visited[nx][ny] || arr[nx][ny]) continue;
                q.push({nx,ny});
                visited[nx][ny]=true;
            }
        }
        for (int x = 0; x < N; x++) {
            for (int y = 0; y < M; y++) {
                if (visited[x][y])
                for (int i = 0; i < 4; i++) {
                    int nx = x+xxxx[i];
                    int ny = y+yyyy[i];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                    arr[nx][ny] = 0;
                }
            }
        }
        bc = count;
    }
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
