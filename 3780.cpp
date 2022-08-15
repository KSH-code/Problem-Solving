#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 2e4;

int parent[MAX+1];
int results[MAX+1];

int find(int x) {
    if (parent[x] == x) return x;
    int t = find(parent[x]);
    results[x] += results[parent[x]];
    return parent[x] = t;
}

void solve(){
    int N; cin >> N;
    memset(results, 0, sizeof results);
    for (int i = 1; i <= N; i++) parent[i] = i;
    while (1) {
        char type; cin >> type;
        if (type == 'O') break;

        if (type == 'E') {
            int t; cin >> t;
            find(t);
            cout << results[t] << '\n';
        } else {
            int a,b; cin >> a >> b;
            results[a] = abs(a-b) % 1000;
            parent[a] = b;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    while(N--){
        solve();
    }
    return 0;
}
