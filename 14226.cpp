#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int visited[2000][2000];

struct Node {
    int a,b,c;
};

void solve(){
    int N; cin >> N;
    memset(visited, -1, sizeof visited);
    auto compare = [](const Node a1, const Node a2) {
        auto [a,b,c] = a1;
        auto [e,f,g] = a2;
        return b > f;
    };
    priority_queue<Node, vector<Node>, decltype(compare)> q(compare);
    q.push({1,0,0});
    visited[1][0] = 0;
    while(q.size()) {
        auto [a,b,c] = q.top(); q.pop();
        if (visited[a][c] != b) continue;
        if (a == N) {
            cout << b;
            return;
        }
        if (c && a+c < 2000) {
            if (visited[a+c][c] == -1 || visited[a+c][c] > b+1) {
                visited[a+c][c] = b+1;
                q.push({a+c,b+1,c});
            }
        }
        for (int i = a-1; i >= 1; i--) {
            if (visited[i][c] == -1 || visited[i][c] > b+a-i) {
                visited[i][c] = b+a-i;
                q.push({i,b+a-i,c});
            }
        }
        if (visited[a][a] == -1 || visited[a][a] > b+1) {
            visited[a][a] = b+1;
            q.push({a,b+1,a});
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
