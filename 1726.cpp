#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={0,0,1,-1,-1,1,1,-1};
int yyyy[]={1,-1,0,0,-1,1,-1,1};

struct Node {
    int x, y, d, c;
};

void solve(){
    int N, M; cin >> N >> M;
    bool blocked[N+1][M+1]; for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> blocked[i][j];

    int counts[N+1][M+1][5]; memset(counts, 0x3f, sizeof counts);
    int sx, sy, sd; cin >> sx >> sy >> sd;
    int ex, ey, ed; cin >> ex >> ey >> ed;
    if (sx == ex && sy == ey && sd == ed) {
        cout << 0;
        return;
    }
    queue<Node> q; q.push({sx, sy, sd, 0}); counts[sx][sy][sd] = 0;
    while (q.size()) {
        auto [x, y, d, c] = q.front(); q.pop();
        int nc = c + 1;
        for (int i = 1; i <= 3; i++) {
            int nx = x + xxxx[d-1] * i;
            int ny = y + yyyy[d-1] * i;
            if (nx < 1 || ny < 1 || nx > N || ny > M) continue;
            if (blocked[nx][ny]) break;
            if (counts[nx][ny][d] <= nc) continue;
            q.push({nx, ny, d, nc});
            counts[nx][ny][d] = nc;
            if (ex == nx && ey == ny && d == ed) {
                cout << nc;
                return;
            }
        }
        int dddd[5][2] = {
            {-1,-1},
            {3,4},
            {3,4},
            {1,2},
            {1,2}
        };

        for (int i = 0; i < 2; i++) {
            int nd = dddd[d][i];
            if (counts[x][y][nd] <= nc) continue;
            q.push({x, y, nd, nc});
            counts[x][y][nd] = nc;
            if (ex == x && ey == y && nd == ed) {
                cout << nc;
                return;
            }
        }
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
