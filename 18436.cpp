#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 1e5;
int tree[MAX*4][2];

void update(int s, int e, int node, int index, int value) {
    if (s > index || e < index) return;

    if (s == e) {
        tree[node][(value+1)%2]=0;
        tree[node][value]=1;
        return;
    }

    int m = (s+e)/2;
    update(s,m,node*2,index,value);
    update(m+1,e,node*2+1,index,value);

    tree[node][0] = tree[node*2][0] + tree[node*2+1][0];
    tree[node][1] = tree[node*2][1] + tree[node*2+1][1];
}

int query(int s, int e, int node, int l, int r, int v) {
    if (s > r || e < l) return 0;
    if (s >= l && r >= e) return tree[node][v];
    int m = (s+e)/2;
    return query(s,m,node*2,l,r,v) + query(m+1,e,node*2+1,l,r,v);
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1, N, 1, i, a%2);
    }

    int M; cin >> M;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        // 1 i x: Ai를 x로 바꾼다.
        // 2 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 짝수의 개수를 출력한다.
        // 3 l r: l ≤ i ≤ r에 속하는 모든 Ai중에서 홀수의 개수를 출력한다.
        if (a == 1) {
            update(1, N, 1, b, c%2);
            continue;
        }

        cout << query(1, N, 1, b, c, a%2);
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
