#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

typedef pair<int,int> pii;

struct Node {
    int e, w, i;
};

void solve(){
    int N, M;
    cin >> N >> M;
    int s,e; cin >> s >> e;
    vector<vector<Node>> edges(N);
    for (int i = 0; i < M; i++) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({b,c,i});
        edges[b].push_back({a,c,i});
    }

    priority_queue<pii> q;
    bool visited[M]; memset(visited, 0, sizeof visited);
    q.push({1000, s});
    int result = -1;
    while (q.size()) {
        auto [y,x] = q.top(); q.pop();
        if (x == e) {
            cout << y;
            return;
        }

        for (auto [nx, w, i] : edges[x]) {
            if (visited[i]) continue;

            int nw = min(w,y);
            visited[i] = true;
            q.push({nw,nx});
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
