#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

int parent[1000*1001];
string strs[1000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(x)] = find(y);
}

void go(int x, int y) {
    int nx = x;
    int ny = y;
    switch(strs[x][y]) {
        case 'L':
            ny--;
            break;
        case 'R':
            ny++;
            break;
        case 'U':
            nx--;
            break;
        case 'D':
            nx++;
            break;
    }
    merge(x*1000+y,nx*1000+ny);
}

void solve(){
    int N, M; cin >> N >> M;
    for (int i = 0; i < 1000*1001; i++) parent[i] = i;
    for (int i = 0; i < N; i++) cin >> strs[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            go(i, j);
        }
    }
    set<int> s;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
        s.insert(find(i*1000+j));
    }
    cout << s.size();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
