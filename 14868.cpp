#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 1e5;

int parent[MAX+1];
int count[MAX+1];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(y)] = find(x);
}

typedef pair<int,int> pii;

void solve(){
    int N, M; cin >> N >> M;
    int arr[N][N]; memset(arr, 0, sizeof arr);
    int dominated[N][N]; memset(dominated, 0, sizeof dominated);

    queue<pii> q;

    bool visited[N][N]; memset(visited, 0, sizeof visited);
    int tc = 0;
    for (int i = 1; i <= M; i++) {
        parent[i] = i;
        int x,y; cin >> x >> y;
        x--;y--;
        dominated[x][y] = parent[i];
        q.push({x,y});
        if (visited[x][y]) tc++;
        visited[x][y] = true;
    }

    if (tc == M - 1) {
        cout << 0;
        return;
    }

    int result = 1;
for (;;result++) {
    queue<pii> nq;
    set<int> checker;
    while (q.size()) {
        auto [x,y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x+xxxx[i];
            int ny = y+yyyy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (dominated[nx][ny]) merge(dominated[nx][ny], dominated[x][y]);
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            nq.push({nx,ny});
            dominated[nx][ny] = dominated[x][y];
            checker.insert(dominated[nx][ny]);

            for (int j = 0; j < 4; j++) {
                auto nnx = nx + xxxx[j];
                auto nny = ny + yyyy[j];
                if (nnx < 0 || nny < 0 || nnx >= N || nny >= N) continue;
                if (dominated[nnx][nny]) merge(dominated[nx][ny], dominated[nnx][nny]);
            }
        }
    }
    q = nq;
    set<int> tc;
    for (auto c : checker) tc.insert(find(c));
    if (tc.size() <= 1) break;
}
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
