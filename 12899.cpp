#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e6;

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
    int N; cin >> N;

    for (int i = 0; i < N; i++) {
        int a,b;cin >> a>>b;
        if (a == 1) {
            update(1,MAX,1,b,1);
        } else {
            int result = query(1, MAX, 1, b);
            cout << result << '\n';
            update(1,MAX,1,result,-1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
