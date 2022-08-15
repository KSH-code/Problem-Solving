#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

using pii = pair<int,int>;
int N, P, K;
vector<vector<pii>> edges(1001);

bool check(int result) {
    priority_queue<pii, vector<pii>, greater<pii>> q; q.push({0,1});
    int distances[N+1]; memset(distances, 0x3f, sizeof distances);
    distances[1] = 0;
    while (q.size()) {
        auto [c, x] = q.top(); q.pop();
        if (x == N) break;
        for (auto [nc, nx] : edges[x]) {
            auto &ref = distances[nx];
            int t = nc >= result;
            if (ref > c + t) {
                ref = c + t;
                q.push({ref, nx});
            }
        }
    }

    return distances[N] <= K;
}

void solve(){
    cin >> N >> P >> K;

    while (P--) {
        int a,b,c; cin >> a >> b >> c;
        edges[a].push_back({c,b});
        edges[b].push_back({c,a});
    }

    int l = 0, r = 1e6+2;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m;
    }

    cout << (l==1e6+1?-1:l);
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
