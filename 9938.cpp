#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 3e5*2;

int parent[MAX+1];
int counts[MAX+1];

int find(int x) {
    if (parent[x] == x) return x;
    counts[parent[x]] += counts[x];
    parent[x] = find(parent[x]);
    counts[x] = 0;
    return parent[x];
}

void merge(int x, int y) {
    parent[find(y)] = find(x);
    find(y);
}

void solve(){
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        parent[i] = i;
        counts[i]++;
    }

    for (int i = 0; i < N; i++) {
        int a,b;cin >> a >> b;
        a = find(a);
        b = find(b);
        merge(a,b);
        if (counts[a] <= 0) {
            cout << "SMECE\n";
        } else {
            counts[a]--;
            cout << "LADICA\n";
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
