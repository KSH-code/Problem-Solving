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
    int x, t, c;
};

void solve(){
    int N;
    int T, M; cin >> N >> T >> M;
    int L; cin >> L;
    vector<vector<tuple<int,int,int>>> edges(N+1);
    while (L--) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        edges[a].push_back({b,c,d});
        edges[b].push_back({a,c,d});
    }

    auto compare = [](Node a, Node b){
        return a.c >= b.c;
    };
    priority_queue<Node, vector<Node>, decltype(compare)> q(compare);
    q.push({1, 0, 0});

    int distances1[N+1]; memset(distances1, 0x3f, sizeof distances1);
    int distances2[N+1]; memset(distances2, 0x3f, sizeof distances2);

    while (q.size()) {
        auto [x, t, c] = q.top(); q.pop();
        if (x == N) {
            cout << c;
            return;
        }
        for (auto [nx, _t, _c] : edges[x]) {
            if (_c + c > M || _t + t > T) continue;

            if (distances2[nx] > _t + t) {
                distances2[nx] = _t + t;
                q.push({nx, _t + t, c + _c});
            }
            if (distances1[nx] > _c + c) {
                distances1[nx] = _c + c;
                q.push({nx, _t + t, c + _c});
            }
        }
    }

    cout << -1;
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
