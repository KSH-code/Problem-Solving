#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N, M; cin >> N >> M;
    int x,y;cin>>x>>y;
    int fx,fy; cin >> fx>>fy;
    bool yes = false;
    yes=(N%2!=y)&&(fx==N&&fy!=M);
    cout << (yes?"YES!":"NO...");
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
