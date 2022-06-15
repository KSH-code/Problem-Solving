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
    bool arr[N][M]; for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) cin >> arr[i][j];


    int visited[N][M]; memset(visited, 0, sizeof visited);

    int area_count = 0;
    map<int, vector<pair<int,int>>> data;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (!arr[i][j]) visited[i][j] = -1;
        if (visited[i][j]) continue;
        queue<pair<int,int>> q; q.push({i,j});
        area_count++;
            data[area_count].push_back({i,j});
            visited[i][j]=area_count;

        while (q.size()) {
            auto [x,y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                auto nx = x+xxxx[k];
                auto ny = y+yyyy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (!arr[nx][ny]) continue;
                if (visited[nx][ny]) continue;

                visited[nx][ny] = area_count;
                q.push({nx,ny});
                data[area_count].push_back({nx,ny});
            }
        }
    }

    int result = 0;

    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        if (arr[i][j]) continue;
        set<int> f;
        int r = 1;
        for (int k = 0; k < 4; k++) {
            auto nx = xxxx[k]+i;
            auto ny = yyyy[k]+j;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (f.count(visited[nx][ny])) continue;
            if (visited[nx][ny] > -1) {
                f.insert(visited[nx][ny]);
                r += data[visited[nx][ny]].size();
            }
        }
        result = max(result, r);
    }

    cout << (result == 0 ? N*M : result);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
