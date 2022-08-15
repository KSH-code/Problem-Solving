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
    ll A[N+1], B[N+1];
    vector<vector<int>> edges(N+1);
    int results[N+1];
    for (int i = 2; i <= N; i++) {
        int p;cin>>p>>A[i]>>B[i];
        edges[p].push_back(i);
    }
    vector<ll> v;
    function<void(int,ll,ll)> dfs = [&](int x, ll a, ll b) {
        v.push_back(b);
        results[x] = upper_bound(v.begin(), v.end(), a) - v.begin();
        for (auto nx : edges[x]) {
            dfs(nx, a + A[nx], b + B[nx]);
        }
        v.pop_back();
    };
    dfs(1, 0, 0);

    for (int i = 2; i <= N; i++) cout << results[i] - 1 << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
