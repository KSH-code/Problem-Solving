#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

vector<vector<int>> edges(100);
bool visited[101];

bool dfs(int x) {
    for (auto nx : edges[x]) {
        if (visited[nx]) return false;
        visited[nx] = true;
        if (!dfs(nx)) return false;
        visited[nx] = false;
    }
    return true;
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        while (a--) {
            int t; cin >> t;
            edges[i].push_back(t);
        }
    }


    cout << (dfs(1) ? "NO CYCLE" : "CYCLE");
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
