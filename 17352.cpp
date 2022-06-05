#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 3e5;
int parent[MAX+1];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    int px = find(x);
    int py = find(y);
    parent[py] = px;
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) parent[i]=i;
    for (int i = 0; i < N-2; i++) {
        int a,b; cin >> a >> b;
        merge(a,b);
    }
    for (int i = 2; i <= N; i++) {
        if (find(i) != find(i-1)) {
            cout << i << ' ' << i-1;
            return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
