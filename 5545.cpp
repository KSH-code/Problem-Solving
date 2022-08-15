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
    int c,b;cin>>c>>b;
    int r; cin >> r;
    int arr[N]; for (auto &a : arr) cin >> a;
    sort(arr,arr+N);
    for (int i = N-1; i >= 0; i--) {
        if (r*b > arr[i]*c) break;
        r+=arr[i],c+=b;
    }
    cout << r/c;
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
