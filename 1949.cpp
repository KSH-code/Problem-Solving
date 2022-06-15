#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 1e4;
vector<vector<int>> edges(MAX+1);

int memo[MAX+1][2];

int arr[MAX+1];

int dfs(int x, int px, bool mark) {
    int &result = memo[x][mark];
    if (result > 0) return result;

    if (mark) result += arr[x];

    for (auto nx : edges[x]) {
        if (nx == px) continue;

        if (!mark) result += max(dfs(nx, x, mark), dfs(nx, x, !mark));
        else result += dfs(nx, x, !mark);
    }
    return result;
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 2; i <= N; i++) {
        int u,v;cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cout << max(dfs(1, -1, true), dfs(1, -1, false));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
