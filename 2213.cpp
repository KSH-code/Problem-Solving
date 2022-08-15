#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 1e4;
int weights[MAX+1];

vector<vector<int>> edges(MAX+1);

int dp[MAX+1][2];
int next[MAX+1][2];

int dfs(int px, int x, int marked) {
    auto &cur = dp[x][marked];
    if (cur > -1) return cur;

    cur = marked ? weights[x] : 0;
    for (auto nx : edges[x]) {
        if (nx == px) continue;

        if (!marked) {
            cur += max(dfs(x, nx, 0), dfs(x, nx, 1));
        } else {
            cur += dfs(x, nx, 0);
        }
    }

    return cur;
}

vector<int> result;

void trace(int px, int x, int marked) {
    for (auto nx : edges[x]) {
        if (nx == px) continue;

        if (!marked) {
            if (dfs(x, nx, 0) <= dfs(x, nx, 1)) {
                trace(x, nx, 1);
                result.push_back(nx);
                continue;
            }
        }
        trace(x, nx, 0);
    }
}

void solve(){
    int N; cin >> N;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= N; i++) cin >> weights[i];

    for (int i = 1; i < N; i++) {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    cout << max(dfs(-1,1,0), dfs(-1,1,1)) << '\n';
    if (dfs(-1,1,0) <= dfs(-1,1,1)) {
        cout << 1 << ' ';
        trace(-1,1,1);
    } else {
        trace(-1,1,0);
    }
    sort(result.begin(), result.end());
    for (auto r : result) cout << r << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
