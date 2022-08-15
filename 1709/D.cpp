#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 2e5;
int tree[MAX * 4];

void update(int s, int e, int node, int l, int r, int f) {
    if (e < l || s > r) return;
    if (s >= l && r >= e) {
        tree[node] = f;
        return;
    }
    int m = (s+e)/2;
    update(s, m, node*2, l, r, f);
    update(m+1, e, node*2+1, l, r, f);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int s, int e, int node, int l, int r) {
    if (e < l || s > r) return 0;
    if (s >= l && e <= r) return tree[node];
    int m = (s+e)/2;
    return max(query(s,m,node*2,l,r), query(m+1,e,node*2+1,l,r));
}

void solve(){
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a; cin >> a;
        update(1, M, 1, i, i, a);
    }
    int T; cin >> T;
    while (T--) {
        int sx, sy, ex, ey, K; cin >> sx >> sy >> ex >> ey >> K;
        if (sy > ey) {
            swap(sy, ey);
            swap(ex, sx);
        }

        if (sx % K == ex % K && sy % K == ey % K) {
            int h = query(1, M, 1, sy, ey);
            int mx = min(sx, ex);
            if (mx > h) {
                cout << "YES\n";
                continue;
            }

            int up_times = (h - mx) / K + 1;
            if (up_times * K + mx <= N) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
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
