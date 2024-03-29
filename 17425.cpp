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
ll f[MAX+1];

void init(){
    f[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        for (int j = 1; j * i <= MAX; j++) f[i * j] += j;
    }
    for (int i = 2; i <= MAX; i++) f[i] += f[i-1] + i;
}

void solve(){
    int N; cin >> N;
    cout << f[N];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    init();
    int T=1;
    cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
