#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

typedef pair<int,int> pii;
const int MAX = 20;

void solve(){
    int N,M;cin>>N;
    int depth[N+1]; memset(depth, 0, sizeof depth);
    depth[1]=1;
    vector<vector<pii>> edges(N+1);
    for (int i = 0; i < N-1; i++) {
        int u,v,w;cin >> u >> v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }

    queue<int> q; q.push(1);

    int parent[MAX][N+1];
    pii results[MAX][N+1]; for (int i = 0; i < MAX; i++) for (int j = 1; j <= N; j++) results[i][j] = {1e6,0};

    while (q.size()) {
        auto x = q.front();q.pop();
        for (auto [nx, w] : edges[x]) {
            if (depth[nx]) continue;
            depth[nx]=depth[x]+1;
            q.push(nx);
            parent[0][nx]=x;
            results[0][nx]={w,w};
        }
    }
    parent[0][1]=1;
    for (int j = 1; j < MAX; j++) {
        for (int i = 1; i <= N; i++) {
            int next = parent[j-1][i];
            parent[j][i] = parent[j-1][next];
            auto [a, b] = results[j-1][next];
            auto [c, d] = results[j-1][i];
            results[j][i] = {min(a,c), max(b,d)};
        }
    }

    cin >> M;

    while (M--) {
        int a,b; cin >> a >> b;
        if (depth[a] > depth[b]) swap(a,b);

        int jump = 1;
        while (depth[parent[jump][b]] > depth[a]) jump++;
        jump--;

        int _min = 1e6;
        int _max = 0;

        while (depth[b] > depth[a]) {
            while (depth[parent[jump][b]] < depth[a]) jump--;
            auto [x1,x2] = results[jump][b];
            _min = min(_min,x1);
            _max = max(_max,x2);
            b = parent[jump][b];
        }

        while (a != b) {
            jump = 1;
            while (parent[jump][b] != parent[jump][a]) jump++;
            jump--;

            auto [x1,x2] = results[jump][a];
            auto [x3,x4] = results[jump][b];
            _min = min({_min,x1,x3});
            _max = max({_max,x2,x4});

            a = parent[jump][a];
            b = parent[jump][b];
        }

        cout << _min << ' ' << _max << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
