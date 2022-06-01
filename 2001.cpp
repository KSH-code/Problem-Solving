#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

struct Edge {
    int v,c;
};

struct Node {
    int x,c;
    int v;
};

typedef pair<int,int> pii;

void solve(){
    int N, M, K; cin >> N >> M >> K;
    int gems[K];

    vector<vector<Edge>> edges(N+1);

    for (int i = 0; i < K; i++) cin >> gems[i];

    for (int i = 0; i < M; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        edges[u].push_back({v,c});
        edges[v].push_back({u,c});
    }

    int result = 0;
    bool visited[1<<K][N+1];
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < K; i++) {
        queue<Node> q;
        q.push({i,1,1<<i});

        while (q.size()) {
            auto [x,c,v] = q.front(); q.pop();
            if (x == 1) result = max(result, c);

            for (auto [nx, limit] : edges[x]) {
                if (limit < c) continue;
                if (visited[v][nx]) continue;

                visited[v][nx]=true;
                q.push({nx,c,v});

                for (int j = 0; j < K; j++) {
                    if (gems[j] == nx && (v&1<<j) == 0) {
                        q.push({nx,c+1,v|1<<j});
                    }
                }
            }
        }
    }


    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
