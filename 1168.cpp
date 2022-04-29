#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5;

int tree[MAX*4];

int query(int s, int e, int node, int rank) {
    if (s == e) return s;

    int m = (s+e)/2;
    if (tree[node*2] >= rank) return query(s, m, node*2, rank);
    else return query(m+1, e, node*2+1, rank-tree[node*2]);
}

void update(int s, int e, int node, int index, int diff) {
    if (e < index || index < s) return;
    tree[node] += diff;
    if (s == e) return;

    int m = (s+e)/2;
    update(s, m, node*2, index, diff);
    update(m+1, e, node*2+1, index, diff);
}

void solve(){
    int N,K; cin >> N >> K;
    for (int i = 1; i <= N; i++) update(1, N, 1, i, 1);

    int step = 1;
    for (int i = 1; i <= N; i++) {
        step = (step + (K-1)) % (N-i+1);
        if (step == 0) step = N-i+1;

        int result = query(1, N, 1, step);
        cout << result;
        update(1, N, 1, result, -1);
        if (i < N) cout << ", ";
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout << '<';
    solve();
    cout << '>';
    return 0;
}
