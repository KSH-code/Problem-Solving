#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int v,w;
};

const ll MOD = 1e9+7;

const int MAX = 1e5;
vector<vector<Edge>> edges(MAX+1);

ll result;
ll dfs(int n, int p) {
    ll data = 1;
    for (auto [v,w] : edges[n]) {
        if (v == p) continue;
        ll sub = (dfs(v, n) * w) % MOD;
        result = (result + data * sub) % MOD;
        data = (data + sub) % MOD;
    }
    return data;
}

void solve(){
    int N; cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u,v,w;cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    dfs(1, 0);
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
