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
    int visited, x, w;
};

void solve(){
    int N, s; cin >> N >> s;
    int edges[N][N]; for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)cin >> edges[i][j];
    auto compare = [](const Node a, const Node b){
        return a.w > b.w;
    };
    priority_queue<Node, vector<Node>, decltype(compare)> q(compare);
    q.push({1<<s,s,0});

    int visited[1<<N][N]; memset(visited, 0x3f, sizeof visited);
    int result = 1e9;
    while (q.size()) {
        auto [mark, x, w] = q.top(); q.pop();
        if (mark+1 == 1<<N) {
            cout << w;
            return;
        }
        for (int i = 0; i < N; i++) {
            int nx = mark | 1 << i;
            int &nw = visited[nx][i];
            if (nw <= w + edges[x][i]) continue;
            nw = w + edges[x][i];
            q.push({nx, i, nw});
        }
    }
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
