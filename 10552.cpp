#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;

bool visited[MAX+1];

int edges[MAX+1];

int N,M,P;
int fr = MAX;

int dfs(int u) {
    int v = edges[u];
    if (!v) return 0;

    if (!visited[v]) {
        visited[v] = true;
        return dfs(v) + 1;
    } else fr = -1;

    return 0;
}

void solve(){
    cin >> N >> M >> P;
    for (int i = 1; i <= N; i++) {
        int u,v;cin>>v>>u;
        if (edges[u]) continue;
        edges[u]=v;
    }

    int result = dfs(P);

    cout << min(fr,result);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;

}
