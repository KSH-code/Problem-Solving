#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 1e5;

ll tree[MAX*4];
ll lazy[MAX*4];

void propagate(int s, int e, int node) {
    if (!lazy[node]) return;

    tree[node] += lazy[node]*(e-s+1);
    if (s != e) for (int i = node*2; i <= node*2+1; i++) lazy[i] += lazy[node];
    lazy[node] = 0;
}

ll query(int s, int e, int node, int l, int r) {
    propagate(s, e, node);
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return tree[node];

    int m = (s+e)/2;
    return query(s,m,node*2,l,r) + query(m+1,e,node*2+1,l,r);
}

void update(int s, int e, int node, int l, int r, int diff) {
    propagate(s, e, node);
    if (l > e || s > r) return;
    if (l <= s && e <= r) {
        lazy[node] = diff;
        return;
    }

    int m = (s+e)/2;
    update(s,m,node*2,l,r,diff);
    update(m+1,e,node*2+1,l,r,diff);

    tree[node] = tree[node*2] + tree[node*2+1];
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1, N, 1, i, i, a);
    }

    int M; cin >> M;
    while (M--) {
        int t; cin >> t;
        if (t == 1) {
            int a,b,c;cin>>a>>b>>c;
            update(1,N,1,a,b,c);
        } else {
            int a; cin >> a;
            cout << query(1,N,1,a,a)<<'\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
