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
    int N; cin >> N;
    int arr[N+1]; arr[0]=0;
    for (int i = 1; i <= N; i++) {
        int z; cin >> z;
        arr[i] = arr[i-1] + z;
    }

    int M; cin >> M;
    while (M--) {
        int s,e;cin>>s>>e;
        cout << arr[e]-arr[s-1] << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
