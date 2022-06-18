#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


const int MAX = 20;

void solve(){
    int N,M;cin>>N;
    int depth[N+1]; memset(depth, 0, sizeof depth);
    depth[1]=1;
    vector<vector<int>> edges(N+1);
    for (int i = 0; i < N-1; i++) {
        int u,v;cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    queue<int> q; q.push(1);

    int parent[MAX][N+1];

    while (q.size()) {
        auto x = q.front();q.pop();
        for (auto nx : edges[x]) {
            if (depth[nx]) continue;
            depth[nx]=depth[x]+1;
            q.push(nx);
            parent[0][nx]=x;
        }
    }
    parent[0][1]=1;
    for (int j = 1; j < MAX; j++) {
        for (int i = 1; i <= N; i++) {
            parent[j][i] = parent[j-1][parent[j-1][i]];
        }
    }

    cin >> M;

    while (M--) {
        int a,b; cin >> a >> b;
        if (depth[a] > depth[b]) swap(a,b);

        int jump = 1;
        while (depth[parent[jump][b]] > depth[a]) jump++;
        jump--;

        while (depth[b] > depth[a]) {
            while (depth[parent[jump][b]] < depth[a]) jump--;
            b = parent[jump][b];
        }

        while (a != b) {
            jump = 1;
            while (parent[jump][b] != parent[jump][a]) jump++;
            jump--;
            a = parent[jump][a];
            b = parent[jump][b];
        }

        cout << a << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
