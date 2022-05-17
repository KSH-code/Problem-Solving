#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int N,M,K;
    cin >> N >> M >> K;

    bool garbages[N+1][M+1]; memset(garbages, 0, sizeof(garbages));
    while (K--) {
        int x,y;cin>>x>>y;
        garbages[x][y]=true;
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!garbages[i][j]) continue;

            int temp_result = 0;
            queue<pair<int,int>> q;
            q.push({i,j});
            garbages[i][j]=false;
            while (q.size()) {
                temp_result++;
                auto [x,y]=q.front(); q.pop();

                int xxxx[4]={-1,0,1,0};
                int yyyy[4]={0,1,0,-1};
                for (int i = 0; i < 4; i++) {
                    auto nx = x+xxxx[i];
                    auto ny = y+yyyy[i];
                    if (nx<=0||ny<=0||nx>N||ny>M||!garbages[nx][ny]) continue;
                    garbages[nx][ny]=false;
                    q.push({nx,ny});
                }
            }

            result=max(result, temp_result);
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
