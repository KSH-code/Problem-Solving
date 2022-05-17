#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int v,c,t;
};

const int MAX = 1e9;

void solve(){
    int N, M, S, E; cin >> N >> M >> S >> E;

    vector<vector<Node>> edges(N+1);
    while(M--) {
        int u,v,c,t; cin >> u >> v >> c >> t;
        edges[u].push_back({v,c,t});
        edges[v].push_back({u,c,t});
    }

    set<pair<int,int>> time_efficent;
    queue<Node> q;
    q.push({S,0,0});

    int times[N+1]; for (int i = 0; i <= N; i++) times[i] = MAX;
    set<int> gg[N+1];
    times[S] = 0;
    while (q.size()) {
        auto [x,c,t] = q.front(); q.pop();
        if (x == E) {
            time_efficent.insert({t,c});
        }

        for (auto [v,nc,nt] : edges[x]) {
            nc = nc + c;
            nt = nt + t;

            if (times[v] > nt) gg[v].clear();
            if (times[v] > nt || (times[v] == nt && !gg[v].count(nc))) {
                gg[v].insert(nc);
                q.push({v,nc,nt});
                times[v] = nt;
            }
        }
    }

    set<pair<int,int>> cost_efficent;
    q.push({S,0,0});

    int costs[N+1]; for (int i = 0; i <= N; i++) costs[i] = MAX;
    for (int i = 0; i <= N; i++) gg[i].clear();
    costs[S] = 0;
    while (q.size()) {
        auto [x,c,t] = q.front(); q.pop();
        if (x == E) {
            cost_efficent.insert({c,t});
        }

        for (auto [v,nc,nt] : edges[x]) {
            nc = nc + c;
            nt = nt + t;

            if (costs[v] > nc) gg[v].clear();
            if (costs[v] > nc || (costs[v] == nc && !gg[v].count(nt))) {
                q.push({v,nc,nt});
                costs[v]=nc;
                gg[v].insert(nt);
            }
        }
    }

    int result = 1;
    int checker = MAX;
    for (auto [a,b] : time_efficent) {
        checker = min(checker, a);
        if (a > checker) break;

        bool found = false;
        for (auto [c,d] : cost_efficent) {
            if (a >= d) found = true;
        }
        if (found) break;

        result++;
    }

    checker = MAX;
    for (auto [a,b] : cost_efficent) {
        checker = min(checker, a);
        if (a > checker) break;

        bool found = false;
        for (auto [c,d] : time_efficent) {
            if (a >= d) found = true;
        }
        if (found) break;

        result++;
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
