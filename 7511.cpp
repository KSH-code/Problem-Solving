#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 1e6;
int parents[MAX];

int find(int x) {
    if (parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

void solve(){
    int N, M; scanf("%d %d" ,&N,&M);
    for (int i = 0; i < N; i++) parents[i] = i;
    while (M--) {
        int a,b; scanf("%d %d",&a,&b);
        parents[find(a)] = parents[find(b)];
    }

    int K; scanf("%d", &K);
    while (K--) {
        int a,b; scanf("%d %d", &a, &b);
        if (find(a) == find(b)) printf("1\n");
        else printf("0\n");
    }
}

int main()
{
    // cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Scenario %d:\n", i);
        solve();
        printf("\n");
    }
    return 0;
}
