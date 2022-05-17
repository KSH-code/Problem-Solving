#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int N,M; cin >> N >> M;
    int parent[N+1];
    vector<vector<int>> edges(N+1);

    while (M--) {
        int u,v;cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int visited[N+1]; memset(visited, 0, sizeof(visited));

    queue<pair<int,int>> q;
    int result = 0;
    bool colored[N+1]; memset(colored, 0, sizeof(colored));

    vector<vector<int>> depths(N+1);

    for (int i = 1; i <= N; i++) {
        if (edges[i].size() && !visited[i]) {
            q.push({i, 1});
            visited[i] = i;

            while (q.size()) {
                auto [node, depth] = q.front(); q.pop();
                depths[depth].push_back(node);

                int next_depth = depth + 1;
                for (auto next_node : edges[node]) {
                    if (visited[next_node]) continue;
                    visited[next_node] = node;
                    q.push({next_node, next_depth});
                }
            }
        }
    }

    for (int depth = N; depth >= 2; depth--) {
        for (auto node : depths[depth]) {
            if (colored[node]) continue;

            int parent = visited[node];
            colored[parent] = true;

            for (auto adjacent : edges[parent]) colored[adjacent] = true;
            result++;
        }
    }

    for (int i = 1; i <= N; i++) if (!colored[i]) result++;

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
