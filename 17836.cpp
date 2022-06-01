#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

struct Node {
    int x,y,c;
    bool force;
};

void solve(){
    int N, M, K; cin >> N >> M >> K;
    int arr[N][M];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];

    bool visited[N][M][2]; memset(visited, 0, sizeof(visited));
    queue<Node> q; q.push({0,0,0,false});
    while (q.size()) {
        auto [x,y,c,force]=q.front();q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x+xxxx[i];
            int ny = y+yyyy[i];
            if (nx < 0 || ny <0 || nx>=N ||ny>=M) continue;
            if(visited[nx][ny][force]) continue;
            if (arr[nx][ny]==1 && !force) continue;
            auto nf=force||arr[nx][ny]==2;
            auto nc =c+1;
            if (nc>K) continue;
            if(nx==N-1&&ny==M-1) {
                cout << nc;
                return;
            }
            visited[nx][ny][nf]=true;
            q.push({nx,ny,nc,nf});
        }
    }

    cout << "Fail";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
