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
    int a,b;cin>>a>>b;
    for (int i = 9; i >= 0; i--) {
        if (a >= (1<<i)) a-=1<<i;
    }

    if (a==0) {
        cout << "No thanks";
        return;
    }

    b&=a;
    if (b==a)
        cout << "Thanks";
    else
        cout << "Impossible";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
