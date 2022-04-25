#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int x;
    ll w;
};

struct Compare{
    bool operator()(const Node &a, const Node &b) {
        return a.w > b.w;
    }
};

void solve(){
    int N; cin >> N;
    ll edges[N][N];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> edges[i][j];

    ll nodes[N];

    priority_queue<Node, vector<Node>, Compare> pq;
    pq.push({0,0});
    bool visited[N]; memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) nodes[i] = 1e10;

    ll result = 0;
    while (pq.size()) {
        auto [x,w] = pq.top(); pq.pop();
        if (nodes[x] < w) continue;

        if (!visited[x]) {
            result += w;
            nodes[x] = w = 0;
            visited[x] = true;
        }

        for (int i = 0; i < N; i++) {
            if (i == x) continue;

            if (nodes[i] > w + edges[x][i]) {
                nodes[i] = w + edges[x][i];
                pq.push({i, w + edges[x][i] });
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
