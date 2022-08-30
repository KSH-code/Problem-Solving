#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

struct Node {
    int x, count, weight;
};

void solve(){
    int N, M, K; cin >> N >> M >> K;

    int edges[N+1][N+1]; memset(edges, 0, sizeof edges);
    while(K--) {
        int a,b,c; cin >> a >> b >> c;
        edges[a][b] = max(edges[a][b], c);
    }
    int distances[N+1][M+1]; memset(distances, 0, sizeof distances);

    queue<Node> q;
    q.push({1, 1, 0});
    int result = 0;
    while (q.size()) {
        auto [x, c, w] = q.front(); q.pop();
        if (distances[x][c] != w) continue;
        if (x == N) {
            result = max(result, w);
            continue;
        }

        if (c+1 > M) continue;

        for (int i = x + 1; i <= N; i++) {
            if (!edges[x][i]) continue;

            auto &ref = distances[i][c+1];
            if (ref >= edges[x][i] + w) continue;
            ref = edges[x][i] + w;
            q.push({i, c+1, ref});
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
