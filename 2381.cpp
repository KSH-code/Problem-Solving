#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N; cin >> N;
    int z[N];
    int w[N]; for (int i = 0; i < N; i++) {
        int x,y; cin >> x >> y;
        z[i]=x+y;
        w[i]=x-y;
    }
    sort(z,z+N);
    sort(w,w+N);
    int result = max({abs(z[0]-z[N-1]), abs(w[0]-w[N-1])});
    cout << result;
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
