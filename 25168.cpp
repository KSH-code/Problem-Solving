#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

typedef pair<int,int> pii;

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<pii>> edges(N+1);

    int indegree[N+1]; memset(indegree, 0, sizeof(indegree));
    while (M--) {
        int u,v,w;
        cin >> u >> v >> w;
        edges[u].push_back({v,w});
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++) if (!indegree[i]) {
        q.push(i);
    }

    int times[N+1]; memset(times, 0, sizeof(times));
    int r = 0;
    while (q.size()) {
        auto x = q.front(); q.pop();
        r=max(r,times[x]);

        for (auto [nx, ct] : edges[x]) {
            int z = times[x]+ct;
            if (ct >= 7) z++;
            indegree[nx]--;
            times[nx] = max(times[nx], z);
            if(!indegree[nx]) q.push(nx);
        }
    }

    cout << r+1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
