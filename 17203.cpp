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
    int ps[N];
    int arr[N]; for (int i = 0; i < N; i++) cin >> arr[i];
    memset(ps, 0, sizeof ps);
    for (int i = 1; i < N; i++) {
        ps[i] = ps[i-1] + abs(arr[i] - arr[i-1]);
    }

    while(M--) {
        int a,b;cin>>a>>b;
        cout << ps[b-1]-ps[a-1];
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
