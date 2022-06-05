#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6;

int visited[MAX+1];
int memo[MAX+1][2];
vector<vector<int>> edges(MAX+1);

int dfs(int x, int px, bool marked) {
    int &result = memo[x][marked];
    if (result != -1) return result;

    result = marked;

    for (auto nx : edges[x]) {
        if (nx == px) continue;

        if (marked) result += min(dfs(nx, x, !marked), dfs(nx, x, marked));
        else result += dfs(nx, x, !marked);
    }

    return result;
}

void solve(){
    int N; cin >> N;
    int M = N-1;

    memset(memo, -1, sizeof memo);

    while (M--) {
        int u,v;cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    queue<int> q;
    visited[1]=true;
    q.push(1);

    while (q.size()) {
        auto x = q.front(); q.pop();

        for (auto nx : edges[x]) {
            if (visited[nx]) continue;
            visited[nx] = true;
            q.push(nx);
        }
    }

    int result = min({
        dfs(1,-1,true),
        dfs(1,-1,false)
    });

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
