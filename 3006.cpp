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
int tree[MAX*4];
int arr[MAX+1];

int query(int s, int e, int node, int l, int r) {
    if (l > e || s > r) return 0;
    if (l <= s && e <= r) return tree[node];
    int m = (s+e)/2;
    return query(s,m,node*2,l,r) + query(m+1,e,node*2+1,l,r);
}

void update(int s, int e, int node, int index, int diff) {
    if (index > e || index < s) return;
    tree[node] += diff;
    if (s == e) return;

    int m = (s+e)/2;
    update(s,m,node*2,index,diff);
    update(m+1,e,node*2+1,index,diff);
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        update(1,N,1,i, 1);
        arr[a]=i;
    }

    for (int i = 1; i <= N; i++) {
        int moved = 0;
        int p = 0;
        int cur = 0;
        if (i & 1) {
            p = 1+i/2;
            cur = arr[p];
            moved = query(1, N, 1, 1, cur-1);
        } else {
            p = N-i/2+1;
            cur = arr[p];
            moved = query(1, N, 1, cur+1, N);
        }

        update(1, N, 1, cur, -1);

        cout << moved << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
