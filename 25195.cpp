#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<int>> edges(N+1);
    for (int i = 0; i < M; i++) {
        int u,v; cin >> u >> v;
        edges[u].push_back(v);
    }

    int z; cin >> z;

    bool blocked[N+1]; memset(blocked, 0, sizeof(blocked));

    for (int i = 0; i < z; i++) {
        int block; cin >> block;
        blocked[block] = true;
    }

    queue<int> q;
    if (!blocked[1]) q.push(1);
    while (q.size()) {
        auto x = q.front(); q.pop();
        if (edges[x].empty()) {
            cout << "yes";
            return;
        }

        for (auto nx : edges[x]) {
            if (blocked[nx]) continue;
            q.push(nx);
        }
    }
    cout << "Yes";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
