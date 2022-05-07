#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;
int tree[MAX*4];
int lazy[MAX*4];

vector<vector<int>> edges(MAX+1);

int node_count;
int start[MAX+1];
int last[MAX+1];
void dfs(int x, int parent) {
    start[x] = ++node_count;
    for (auto node : edges[x]) {
        dfs(node, x);
    }
    last[x] = node_count;
}

int N, M;

void propagation(int s, int e, int node) {
    if (!lazy[node]) return;
    tree[node] += lazy[node];
    if (s != e) for (int i = node*2; i <= node*2+1; i++) lazy[i] += lazy[node];
    lazy[node] = 0;
}

void update(int s, int e, int node, int l, int r, int diff) {
    if (s > r || e < l) return;
    if (s >= l && e <= r) {
        lazy[node] += diff;
        return;
    }

    int m = (s+e)/2;
    update(s, m, node*2, l, r, diff);
    update(m+1, e, node*2+1, l, r, diff);
}

int query(int s, int e, int node, int l, int r) {
    if (s > r || e < l) return 0;
    propagation(s, e, node);
    if (s >= l && e <= r) return tree[node];
    int m = (s+e)/2;
    return query(s, m, node*2, l, r) + query(m+1, e, node*2+1, l , r);
}

void solve(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int parent; cin >> parent;
        if (i > 1) edges[parent].push_back(i);
    }

    dfs(1, -1);

    while (M--) {
        int a,b;
        cin >> a >> b;
        if (a == 1) {
            int c; cin >> c;
            update(1, N, 1, start[b], last[b], c);
        } else {
            cout << query(1, N, 1, start[b], start[b]);
            cout << '\n';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
