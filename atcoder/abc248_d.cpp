#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5;

unordered_map<int, int> tree[MAX*4];

void update(int s, int e, int node, int index, int f) {
    if (s > index || e < index) return;

    tree[node][f]++;
    if (s == e) return;

    int m = (s+e)/2;
    update(s, m, node*2, index, f);
    update(m+1, e, node*2+1, index, f);
}

int query(int s, int e, int node, int l, int r, int c) {
    if (s > r || e < l) return 0;
    if (l <= s && r >= e) {
        if (tree[node].count(c)) return tree[node][c];
        return 0;
    }

    int m = (s+e)/2;
    return query(s, m, node*2, l, r, c) + query(m+1, e, node*2+1, l, r, c);
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1, N, 1, i, a);
    }

    int M; cin >> M;
    while (M--) {
        int l, r, c;
        cin >> l >> r >> c;
        cout << query(1, N, 1, l, r, c);
        cout << '\n';
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
