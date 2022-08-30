#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N; cin >> N;
    vector<vector<int>> v(N+1);
    int M; cin >> M;
    while (M--) {
        int a,b;cin>>a>>b;
        v[b].push_back(a);
    }
    int X; cin >> X;
    int result = 0;
    queue<int> q; q.push(X);
    bool visited[N+1]; memset(visited, 0, sizeof visited);
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int nx : v[x]) {
            if (visited[nx]) continue;
            q.push(nx); visited[nx] = true;
            result++;
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
