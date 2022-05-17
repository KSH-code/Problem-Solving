#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6;

ll tree[MAX*4];
ll lazy[MAX*4];

void propagate(int s, int e, int node) {
    if (!lazy[node]) return;

    tree[node] += (e-s+1)*lazy[node];
    if (s != e) for (int i = node*2; i <= node*2+1; i++) lazy[i] += lazy[node];
    lazy[node] = 0;
}

void update(int s, int e, int node, int l, int r, ll diff) {
    propagate(s, e, node);
    if (s > r || e < l) return;

    if (s >= l && e <= r) {
        lazy[node] = diff;
        propagate(s, e, node);
        return;
    }

    int m = (s+e)/2;
    update(s, m, node*2, l, r, diff);
    update(m+1, e, node*2+1, l, r, diff);

    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int s, int e, int node, int l, int r) {
    if (s > r || e < l) return 0;

    propagate(s, e, node);
    if (s >= l && e <= r) return tree[node];

    int m = (s+e)/2;
    return query(s, m, node*2, l, r) + query(m+1, e, node*2+1, l , r);
}

void solve(){
    int N, Q1, Q2; cin >> N >> Q1 >> Q2;

    for (int i = 1; i <= N; i++) {
        ll c; cin >> c;
        update(1, N, 1, i,i, c);
    }

    for (int i = 1; i <= Q1 + Q2; i++) {
        int type; cin >> type;
        int s, e; cin >> s >> e;
        if (s > e) swap(s,e);

        if (type == 1) {
            cout << query(1, N, 1, s, e) << '\n';
        } else {
            ll v; cin >> v;
            update(1, N, 1, s, e, v);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
