#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

map<ll, ll> memo;

ll P,Q;

ll dfs(ll x) {
    if (x == 0) return 1;
    if (memo.count(x)) return memo[x];

    memo[x] = dfs(x/P) + dfs(x/Q);
    return memo[x];
}


void solve(){
    ll N;
    cin >> N >> P >> Q;
    cout << dfs(N);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
