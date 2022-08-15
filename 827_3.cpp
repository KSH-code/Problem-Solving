#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 5e5;
int N;
int T;
int f = 0;
vector<vector<int>> edges(MAX+1);

int end_node[MAX+1];
bool visited[MAX+1];

void dfs(int x, int px, int length) {
    for (auto nx : edges[x]) {
        if (nx == px) continue;
        if (visited[nx]) continue;
        visited[nx] = true;
        dfs(nx, x, length + 1);
        visited[nx] = false;
    }
}

void solve(){
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u,v; cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int s, w; cin >> s >> w;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
