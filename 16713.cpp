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
    ll arr[N+1]; memset(arr, 0, sizeof arr);

    for (int i = 1; i<= N; i++) {
        cin >> arr[i];
        arr[i]^=arr[i-1];
    }

    ll result = 0;
    while(M--) {
        int a,b;cin>>a>>b;
        result ^= arr[a-1]^arr[b];
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
